#ifndef Dates_h
#define Dates_h

class Dates
{
public:

	void initializeDates(int yearValue, int monthValue, int weekValue, int daysValue, int leapCounter);
	void increase();
	int getYear();
	int getMonth();
	int getWeek();
	int getDays();
	
private:
	int yearOfSimulation;
	int monthOfYear;
	int weekOfYear;
	int daysInWeek;
	int leapYearCounter;
};	

#endif
