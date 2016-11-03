/*
 * tools.h
 *
 *  Created on: 06.06.2015
 *      Author: Waldemar Leise
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * get Text and reserve memory and release memory
 */
int getText(const char * myStr, const int TxtLaenge, char **InputTxt, int Leer);

/**
 * clear the input buffer
 */
void clearBuffer();

/**
 *
 * @param[in] string
 */
int askYesOrNo(char *Question);

/**
 *
 */
void waitForEnter();

/**
 *
 */
void clearScreen();

/**
 *
 */
void printLine(const char elem, int length);

int fakultaet(int x);

char *toFilename(char *date);
void textBLUE(int i);



#endif /* TOOLS_H_ */
