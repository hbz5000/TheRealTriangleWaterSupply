#ifndef TimeSeriesData_h
#define TimeSeriesData_h

#include "global.h"

class TimeSeriesData
{
	public:
	
	TimeSeriesData();
	~TimeSeriesData();
	
	string name;
	
	data_t stoch1, stoch2;
	int numRows, numRuns;
	bool useSynthetic;
	
	double **rawData, **normalizedData, *averages, *standardDeviations, **normalizedDataAdj, *averagesAdj, *standardDeviationsAdj;
	
	double **simulatedData, **synthetic;
	
	void allocate(int inflowR, int inflowC);
	void allocate(int inflowR, int inflowC, int numWeeks, int numRealizations);
	void calculateNormalizations(int inflowR, int inflowC);
	void calculateNormalizations(int inflowR, int inflowC, int startYear);
	
	
	void generateSynthetic(int **randomIndices, int numWeeks, int numRealizations, bool exponentiate);
	
};

#endif
