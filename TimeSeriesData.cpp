#include "global.h"
#include "TimeSeriesData.h"

using namespace std;

TimeSeriesData::TimeSeriesData()
{
}

TimeSeriesData::~TimeSeriesData()
{
	zap(averages);
	zap(standardDeviations);
	zap(normalizedData, numRows);
	zap(averagesAdj);
	zap(standardDeviationsAdj);
	zap(normalizedDataAdj, numRows);
	zap(rawData, numRows);
	
	if(useSynthetic) 
	{
		zap(simulatedData, numRuns);
		zap(synthetic, numRuns);
	}
}

void TimeSeriesData::allocate(int inflowR, int inflowC)
{
	numRows = inflowR;
	useSynthetic = false;
	
	general_1d_allocate(averages, inflowC, 0.0);
	general_1d_allocate(standardDeviations, inflowC, 0.0);
	general_2d_allocate(normalizedData, inflowR, inflowC, 0.0);
	general_1d_allocate(averagesAdj, inflowC, 0.0);
	general_1d_allocate(standardDeviationsAdj, inflowC, 0.0);
	general_2d_allocate(normalizedDataAdj, inflowR, inflowC, 0.0);
	general_2d_allocate(rawData, inflowR, inflowC, 0.0);
}

void TimeSeriesData::allocate(int inflowR, int inflowC, int numWeeks, int numRealizations)
{
	numRows = inflowR;
	numRuns = numRealizations;
	useSynthetic = true;
	
	general_1d_allocate(averages, inflowC, 0.0);
	general_1d_allocate(standardDeviations, inflowC, 0.0);
	general_2d_allocate(normalizedData, inflowR, inflowC, 0.0);
	general_1d_allocate(averagesAdj, inflowC, 0.0);
	general_1d_allocate(standardDeviationsAdj, inflowC, 0.0);
	general_2d_allocate(normalizedDataAdj, inflowR, inflowC, 0.0);
	general_2d_allocate(rawData, inflowR, inflowC, 0.0);
	
	general_2d_allocate(simulatedData, numRealizations, numWeeks, 0.0);
	general_2d_allocate(synthetic, numRealizations, numWeeks, 0.0);
}

void TimeSeriesData::calculateNormalizations(int inflowR, int inflowC)
{
	for (int column = 0; column < inflowC; column++)
	{
		averages[column] =  average_array_colwise(rawData, inflowR, inflowC, column);
		standardDeviations[column] = std_dev_colwise(rawData, inflowR, column);

		for (int row = 0; row < inflowR; row++)
			normalizedData[row][column] = (rawData[row][column] - averages[column])/standardDeviations[column];
		
	}
	
	//zap(rawData, inflowR);
	
	return;
}
void TimeSeriesData::calculateNormalizations(int inflowR, int inflowC, int startYear)
{
	for (int column = 0; column < inflowC; column++)
	{
		averages[column] =  average_array_colwise(rawData, inflowR, inflowC, column);
		standardDeviations[column] = std_dev_colwise(rawData, inflowR, column);
		averagesAdj[column] =  average_array_colwise(rawData, inflowR, inflowC, column, startYear);
		standardDeviationsAdj[column] = std_dev_colwise(rawData, inflowR, column, startYear);

		for (int row = 0; row < inflowR; row++)
		{
			normalizedDataAdj[row][column] = (rawData[row][column] - averagesAdj[column])/standardDeviationsAdj[column];
			normalizedData[row][column] = (rawData[row][column] - averages[column])/standardDeviations[column];
		}
		
	}
	
	//zap(rawData, inflowR);
	
	return;
}



void TimeSeriesData::generateSynthetic(int** randomNumbers, int terminateYear, int numRealizations, bool exponentiate)
{
	// Local arrays for intermediate calculations
	double inflowsInt1[(terminateYear+1)*52], inflowsInt2[terminateYear*52], randomInflows[(terminateYear+1)*52];
	
	// Reset random data from last simulation
	zeroes(simulatedData, numRealizations, terminateYear*52);
		
	for (int realization = 0; realization < numRealizations; realization++)
	{
		// Clear intermediate calculations for each realization
		zeroes(randomInflows, (terminateYear+1)*52);
		zeroes(inflowsInt1, (terminateYear+1)*52);
		zeroes(inflowsInt2, terminateYear*52);
	
		for (int year = 0; year < (terminateYear+1); year++)
			for (int week = 0; week < 52; week++)
				randomInflows[year*52 + week] = normalizedData[randomNumbers[year + realization*(terminateYear+1)][week]][week];	
			
		for (int year = 0; year < (terminateYear+1); year++)
		{
			for (int weekCycle1 = 0; weekCycle1 < 52; weekCycle1++)
			{
				for (int weekCycle2 = 0; weekCycle2 < 52; weekCycle2++)
				{
					inflowsInt1[year*52 + weekCycle1] += 
						randomInflows[year*52 + weekCycle2]*stoch1[weekCycle2][weekCycle1];
					
					if(year < terminateYear)
						inflowsInt2[year*52 + weekCycle1] += 
							randomInflows[year*52 + weekCycle2 + 26]*stoch2[weekCycle2][weekCycle1];
				}
			}
		}
		
		for (int year = 0; year < terminateYear; year++)
		{
			for (int week = 0; week < 52; week++)
			{
				if (week < 26) //Combining synthetic values from weeks 1-26 and weeks 27-52
					simulatedData[realization][year*52 + week] = inflowsInt2[year*52 + week + 26];
				else
					simulatedData[realization][year*52 + week] = inflowsInt1[year*52 + week + 52];	
					
				if(exponentiate)
					synthetic[realization][year*52 + week] = exp(simulatedData[realization][year*52 + week]*standardDeviations[week] + averages[week]);
				else
					synthetic[realization][year*52 + week] = simulatedData[realization][year*52 + week]*standardDeviations[week] + averages[week];
			}
		}
		
	}
		
}
