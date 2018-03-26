#include "date.h"

int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isLeapYear( struct date d ) {

	if ((d.year & 3) == 0 && ((d.year % 25) != 0 || (d.year & 15) == 0))
		return 1;

	return 0;
}

int numberOfDays( struct date d ) {

	int days;

	if (isLeapYear( d ) && d.month == 2 )
		days = 29;
	else
		days = daysPerMonth[d.month - 1 ];

	return days;

}

/*
 * Function to implement
 */
void tomorrow( struct date d , struct date * t) {
    int day, month, year;
    day = d.day;
    month = d.month;
    year = d.year;

    if(d.day != numberOfDays (d)){
        day++;
        t->day = day;
        t->month = month;
        t->year = year;
    }else if(d.month == 12) {
        year++;
        t->day = 1;
        t->month = 1;
        t->year = year;
    }else {
        month ++;
        t->day = 1;
        t->month = month;
        t->year = year;
    }
	return;
}
