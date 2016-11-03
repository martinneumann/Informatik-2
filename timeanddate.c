/*
 * time-date.c
 *
 *  Created on: 07.10.2016
 *      Author: Waldemar Leise
 */

#include <stdio.h>
#include <stdlib.h>
#include "timeanddate.h"
#include "tools.h"
#include "datastructure.h"

/***********************************************
*
* Local Functions
*
***********************************************/

/* Checks if year is a leap year.
   Reurns 1 or 0.                             */
int isLeapYear(TDate * date)
{
    if(date->Year % 400 == 0)
        return 1;

    else if(date->Year % 100 == 0)
        return 0;

    else if(date->Year % 4 == 0)
        return 1;

    else
        return 0;
}

/* Checks if day of month is valid(1-30).
   Returns 1 or 0.                            */
int checkthirty(TDate * date)
{
    if((date->Day < 31) && (date->Day > 0))
        return 1;
    else
        return 0;
}

/* Checks if day of month is valid(1-31).
   Returns 1 or 0.                            */
int ckeckthirtyone(TDate * date)
{
    if((date->Day < 32) && (date->Day > 0))
        return 1;
    else
        return 0;
}

/* Checks if day of February is valid depending
   on leap year.
   Returns 1 or 0.                            */
int checkfebr(TDate * date)
{
    int leapyear = isLeapYear(date);

    if(leapyear == 0)
    {
        if((date->Day < 30) && (date->Day > 0))
            return 1;
        else
            return 0;
    }
    else if(leapyear == 1)
    {
        if((date->Day < 29) && (date->Day > 0))
            return 1;
        else
            return 0;
    }

    else
        return 0;
}

/* Checks if entered date is valid(format, range).
   Returns 1 or 0.                                */
int isDateValid(TDate * date)
{
    int valid = 0;

    switch(date->Month)
    {
        case  4:
        case  6:
        case  9:
        case 11:    valid = checkthirty(date);
                    break;

        case  2:    valid = checkfebr(date);
                    break;

        default:    valid = ckeckthirtyone(date);

    }
    return valid;
}

/* Checks if entered Time is valid(format, range)
   Returns 1 or 0.                              */
int isTimeValid(TTime * time)
{
    int validhour = 0,
        validminute = 0,
        validsecond = 0;

    if((time->Hour < 24) && (time->Hour > 0))
        validhour = 1;

    if((time->Minute < 60) && (time->Minute > -1))
        validminute = 1;

    if((time->Second < 60) && (time->Second > -1))
        validsecond = 1;

    if((validhour == 1) && (validminute == 1) && (validsecond == 1))
        return 1;

    else
        return 0;
}

/***********************************************
*
* Global Functions
*
***********************************************/
/* Converts entered string to TDay format.
   Checks if input is valid.
   Returns 1 or 0.                            */
int getDateFromString(char *Input, TDate *date)
{
    TDate tmpDate;
    char * day   = Input;
    char * month = NULL;
    char * year  = NULL;

    int valid    = 0,
            i    = 0;

    // search for first delim
    while((*(Input+i) != '.') && (*(Input+i) != '\0'))
        i++;
    i++;
    month = Input+i;

    // search for second delim
    while((*(Input+i) != '.') && (*(Input+i) != '\0'))
        i++;
    i++;
    year = Input+i;

    // string to int
    tmpDate.Day   = atoi(day);
    tmpDate.Month = atoi(month);
    tmpDate.Year  = atoi(year);

    // exit function with 0 if month is not valid
    if((tmpDate.Month < 1) || (tmpDate.Month > 12))
        return 0;

    // check if entered date is valid
    if(isDateValid(&tmpDate))
    {
        // copy valid date into transfered TDate struct
        date->Day   = tmpDate.Day;
        date->Month = tmpDate.Month;
        date->Year  = tmpDate.Year;
        valid = 1;
    }

    else
        valid = 0;

    return valid;
}


/* Converts entered string to TTime format.
   Checks if input is valid.
   Returns 1 or 0.                            */
int getTimeFromString(char *Input, TTime *time)
{
    TTime tmpTime;
    char * hour   = Input;
    char * minute = NULL;
    char * second  = NULL;

    int valid    = 0,
        i        = 0;

    // search for first delim
    while((*(Input+i) != ':') && (*(Input+i) != '\0'))
        i++;
    i++;
    minute = Input+i;

    // search for second delim
    while((*(Input+i) != ':') && (*(Input+i) != '\0'))
        i++;
    i++;
    second = Input+i;

    // string to int
    tmpTime.Hour   = atoi(hour);
    tmpTime.Minute = atoi(minute);
    tmpTime.Second = atoi(second);

    // checks if entered time is valid
    if(isTimeValid(&tmpTime))
    {
        // copy valid time into transfered TTime struct
        time->Hour   = tmpTime.Hour;
        time->Minute = tmpTime.Minute;
        time->Second = tmpTime.Second;
        valid = 1;
    }

    else
        valid = 0;

    return valid;
}
