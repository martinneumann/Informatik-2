/*
 * datastructure.h
 *
 *  Created on: 07.10.2016
 *      Author: Waldemar Leise
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

/******************************
* Global Definitions of Structs
******************************/

#define MAXAPPOINTMENTS 100


typedef enum
{
    NotADay, Mo, Tu, We, Th, Fr, Sa, Su
} TDayOfTheWeek;


typedef struct
{
    int Day,
        Month,
        Year;
    TDayOfTheWeek WeekDay;
} TDate;

typedef struct
{
    int Hour,
        Minute,
        Second;
} TTime;

typedef struct
{
    TDate Date;
    TTime Time;
    TTime* Duration;
    char* Description;
    char* Place;
} TAppointment;

extern int countAppointments;
extern TAppointment Calendar;

#endif /* DATASTRUCTURE_H_ */
