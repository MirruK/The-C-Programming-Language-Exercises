#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day){
    if(year < 0){
        printf("Error: Are you Jesus or what?"); 
        return -1;
    }
    if(month < 1 || month > 12){ printf("Error: We only do Gregorian in this house(month error)"); return -1;}
    if(day < 0 || day > 31){ printf("Error: We only do Gregorian in this house(day error)"); return -1;}
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){
    if(year < 0){
        printf("Error: Are you Jesus or what?"); 
        return;
    }
    if(yearday < 0 || yearday > 366){ 
        printf("Error: We only do Gregorian in this house(yearday error)"); 
        return;
    }
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main(){
    
}
