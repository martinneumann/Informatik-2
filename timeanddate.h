/*
 * timeanddate.h
 *
 *  Created on: 07.10.2016
 *      Author: Waldemar Leise
 */

#ifndef TIMEANDDATE_H_
#define TIMEANDDATE_H_

#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

/***********************************************
* Converts entered string to TDate format.
* Checks if input is valid.
* Returns 1 or 0.
***********************************************/
int getDateFromString(char *Input, TDate *date);

/***********************************************
* Converts entered string to TTime format.
* Checks if input is valid.
* Returns 1 or 0.
***********************************************/
int getTimeFromString(char *Input, TTime *time);

#endif /* TIMEANDDATE_H_ */
