
typedef struct date {	
	int day;
	int month;
	int year;
}date_t;



int isLeapYear( struct date  );
int numberOfDays( struct date );
void tomorrow( struct date , struct date * );
