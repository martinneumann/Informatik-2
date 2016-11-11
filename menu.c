#include "tools.h"

int getMenu (const char* menuHeader, const char** menuSet, int numOfHeaders)
{
    /* Menu-Methode, wird vom Hauptprogramm aufgerufen. */

    int usrInput, i, valid = 0;
    char inputBuff[20];     // Buffer fuer atoi

    do
    {
        clearScreen();
        memset(inputBuff, 0, 20);   // fuellt Speicher (20 bytes) mit inputBuff
        printf("%s\n", menuHeader);
        printLine('=', strlen(menuHeader));

        for (i = 0; i < numOfHeaders; i++)
            // gibt alle Menuepunkte aus.
        {
            printf("%s\n", menuSet[i]);
        }

        printf("\n");

        printf("Ihre Wahl: ");
        valid = scanf("%19[^\n]", inputBuff);
        // scannt den Userinput uns speichert ihn im Buffer zwischen.
        // scanf returnt die Anzahl der erfolgreich eingelesenen Character. Bei 0 chars ist valid also false.
        clearBuffer();

        if (valid)
        {
            usrInput = atoi(inputBuff);

            if (usrInput <= numOfHeaders)
            {
                break;
            }
            else
            {
                printf("Eingabe nicht korrekt!\n");
            }
        }
    }
    while (!valid);

    return usrInput;
}

