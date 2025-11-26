#include "umwandlungInArray.h"
#include <stdio.h>
#include "lcd.h"



void doubleToCharArray(double value, char *out) {
    int index = 0;

    // Ganzzahl-Teil
    int ganz = (int)value;

    // Nachkommastelle
    int nach = (int)((value - ganz) * 10);

    // Hunderter
    if (ganz >= 100) {
      out[index++] = (ganz / 100) + '0';
     ganz %= 100;
    }

    // Zehner
    out[index++] = (ganz / 10) + '0';

    // Einer
    out[index++] = (ganz % 10) + '0';

    // Punkt
    out[index++] = '.';

    // Nachkommaziffer
    out[index++] = nach + '0';

    // Nullterminator
    out[index] = '\0';
}

//Bei jedem durchlauf des Superloops wird eine Stelle des Arrays ausgegeben
void arrayAusgabe(char* array, int position, int zeile){
    char buf[2];
    buf[0] = array[position];
    buf[1] = '\0';

    lcdGotoXY(18 + position, zeile);
    lcdPrintS(buf);
}