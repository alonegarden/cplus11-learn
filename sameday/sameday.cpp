
//
// c++ 11 test 
// 

#include <iostream>
#include <time.h>
#include <string.h>


using namespace std;

inline bool _IsSameDay(uint64_t dwT1, uint64_t dwT2)
{
	struct tm tm1, tm2;
	memset(&tm1, 0, sizeof(tm1));
	memset(&tm2, 0, sizeof(tm2));

	localtime_r((time_t*)(&dwT1), &tm1);
	int year1 = tm1.tm_year + 1900;
	int month1 = tm1.tm_mon + 1;
	int day1 = tm1.tm_mday;
	
	localtime_r((time_t*)(&dwT2), &tm2);
	int year2 = tm2.tm_year + 1900;
	int month2 = tm2.tm_mon + 1;
	int day2 = tm2.tm_mday;
	
	if (year1 == year2 && month1 == month2 && day1 == day2) {
		return true;
	}
	return false;
}

int main()
{
	uint64_t day1 = 1601879283; 
        uint64_t day2 = 1604557672;
	cout << _IsSameDay(day1, day2) <<  endl;
	
	uint64_t day3 = 1601879283; 
	uint64_t day4 = 1601879282; 
	
	cout << _IsSameDay(day3, day4) <<  endl;

	return 0;
}
