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
typedef struct
{
  int Day,
      Month,
      Year;
}TDate;

typedef struct
{
  int Hour,
      Minute,
      Second;
}TTime;

#endif /* DATASTRUCTURE_H_ */
