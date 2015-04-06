#include "global.h"
#include "Dates.h"

using namespace std;

// Coordinates timesteps and calendar dates

void Dates::initializeDates(int yearValue, int monthValue, int weekValue, int daysValue, int leapCounter) 
{
	yearOfSimulation = yearValue;// Year of the simulation
	monthOfYear = monthValue;//month of the year
	weekOfYear = weekValue;//week of the year
	daysInWeek = daysValue;// number of days in a given week
	leapYearCounter = leapCounter;//leap year (additional day)
	return;
}
int Dates::getYear()
{
	return yearOfSimulation;
}
int Dates::getMonth()
{
	return monthOfYear;
}
int Dates::getWeek()
{
	return weekOfYear;
}
int Dates::getDays()
{
	return daysInWeek;
}

void Dates::increase()//Increases the timestep in accordance with the calender
{
	weekOfYear += 1;
	if(weekOfYear < 52)
		daysInWeek = 7;
	
	else if(weekOfYear == 52)
	{
		if (leapYearCounter == 2)
			daysInWeek = 9;
		else
			daysInWeek = 8;		
	}
	else if(weekOfYear == 53)
	{
		yearOfSimulation += 1;
		leapYearCounter += 1;
		
		if (leapYearCounter == 4)
			leapYearCounter=0;
		
		weekOfYear = 1;
		monthOfYear = 1;
		daysInWeek = 7;
	}

	switch(weekOfYear)
	{
		case 1:
			monthOfYear = 1; break;
		case 5:
			monthOfYear = 2; break;
		case 9:
			monthOfYear = 3; break;
		case 14:
			monthOfYear = 4; break;
		case 18:
			monthOfYear = 5; break;
		case 22:
			monthOfYear = 6; break;
		case 27:
			monthOfYear = 7; break;
		case 32:
			monthOfYear = 8; break;
		case 36:
			monthOfYear = 9; break;
		case 41:
			monthOfYear = 10; break;
		case 45:
			monthOfYear = 11; break;
		case 49:
			monthOfYear = 12; break;
		default:
			if (weekOfYear > 52)
				cout << "Week out of calendar";
			if (monthOfYear > 12)
				cout << "Month out of calendar";
	}
	return;
}
