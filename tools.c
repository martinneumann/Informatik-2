/*
 * tools.c
 *
 *  Created on: 06.10.2015
 *      Author: Waldemar Leise
 */

/* module header */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
//#include "escapesequenzen.h"


/******************************************************
 * Local Function#include
 *****************************************************/



/******************************************************
 * Global Functions
 *****************************************************/

 char *toFilename(char *date)
 {
    char *ch1;
    char cdate[6];
    int i = 0;
    ch1 = malloc(sizeof(char*)*11);

    if(ch1 == NULL) return NULL;

    while(i < 6)
    {
      cdate[i] = date[i+4];
      i++;
    }
    sprintf(ch1, "%s'.txt", cdate);

    //ch1[19] = '\0';
    return (char *)ch1;
 }

int getText(const char * Satz, const int laenge, char **Text, int leer)
{

   char *Input = calloc(laenge + 1, sizeof(char));
   char F[20];
   int Erg = 0, Len = 0, wahr = 0;

   if (Input)
   {
      printf("\n%s", Satz);
      sprintf(F,"%%%i[^\n]s", laenge);

      do
      {
         wahr = scanf(F, Input);
         clearBuffer();
         if ((!wahr)&&(leer))
            printf("Bitte Irgendetwas eingeben!\n");
      } while((!wahr) && (leer));

// "Leerzeichen entfernen" noch einfügen
      Len = strlen(Input);
      if (Len > 0)
      {

         *Text = calloc(laenge + 1, sizeof(char));
         if (*Text)
         {
            strncpy(*Text, Input, laenge);
            Erg = 1;
         }
         else
            Erg = 0;
      }
      else
      {
         if (leer == 0)
         {
            Erg = 1;
            *Text = NULL;
         }
         else
            Erg = 0;
      }
   }
   else
      Erg = 0;

   free(Input);
   return Erg;
}


void clearBuffer()
{
	char trash;
	do
	{
		scanf("%c",&trash);
	} while ( trash != '\n' );
}

int askYesOrNo(char *Question) {
	//
	char input_value;
	int read = 0;

	// input loop
	do {
		printf("%s\n", Question);
		read = scanf("%c",&input_value);
		clearBuffer();

  			// check if yes or no
        switch( input_value ){
  			case 'j':
  			case 'J':   return 1;
  			case 'n':
  			case 'N':
                        return 0;
            default:
                        read = 0;
                        printf("Ungültige Eingabe!!\n");
        }


  }while ( !read );

	return 0;
}

void printLine(char Icon, int Anz)
{
   int i;
   for (i = 0; i < Anz; i++)
      printf("%c", Icon);

   printf("\n");
}

void clearScreen()
{
    #ifdef __WIN32__
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

void waitForEnter() {
    printf("Drücken Sie Enter.\n");
	char c;
	scanf("%c", &c);
}

int fakultaet(int x)
{
	if(x > 1)
		return x * fakultaet(x-1);
  else
 		return x;

}

/*
void POSITION(int y, int x) {
  COORD cur = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}*/


//void textBLUE(int i)
//{
/*
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
*/
    /*
     * First save the current color information
     */
//    GetConsoleScreenBufferInfo(h, &csbiInfo);
  //  wOldColorAttrs = csbiInfo.wAttributes;

    /*
     * Set the new color information
     */
  //  SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN); // | FOREGROUND_INTENSITY
  //FORECOLOR_GREEN;
    //printf("%2d: ", i+1);
  //FORECOLOR_WHITE;
    /*
     * Restore the original colors
     */
    //SetConsoleTextAttribute ( h, wOldColorAttrs);
//}
