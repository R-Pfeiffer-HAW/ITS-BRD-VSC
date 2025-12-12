#include "display_update.h"
#include "lcd.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
 
#define SIZE 10
#define VALUE_MAX_LEN SIZE
 
static char arrayWinkel[VALUE_MAX_LEN];
static char arrayGeschw[VALUE_MAX_LEN];
 
static char lastArrayWinkel[VALUE_MAX_LEN];
static char lastArrayGeschw[VALUE_MAX_LEN];
 
static int pos = 0; // aktuelle Ziffer pro Super-Loop
 
void updateDisplay(double winkel, double geschw, bool *ausgabeKomplett)
{
    // --- Strings vorbereiten ---
    snprintf(arrayWinkel, sizeof(arrayWinkel), "%.0f", winkel);   // Drehwinkel: Ganzzahl
    snprintf(arrayGeschw, sizeof(arrayGeschw), "%.2f", geschw); // Geschwindigkeit: 2 Nachkommastellen
 
    int lenW = strlen(arrayWinkel);
    int lenG = strlen(arrayGeschw);
 
    char out = {0}; // Hilfspuffer für ein einzelnes Zeichen
 
    // --- Drehwinkel: eine Ziffer pro Loop ---
    if (pos < lenW && arrayWinkel[pos] != lastArrayWinkel[pos])
    {
        lcdGotoXY(18 + pos, 2);
        out = arrayWinkel[pos];
        lcdPrintC(out);
        lastArrayWinkel[pos] = arrayWinkel[pos];
    }
 
    // --- Winkelgeschwindigkeit: eine Ziffer pro Loop ---
    if (pos < lenG && arrayGeschw[pos] != lastArrayGeschw[pos])
    {
        lcdGotoXY(18 + pos, 5);
        out = arrayGeschw[pos];
        lcdPrintC(out);
        lastArrayGeschw[pos] = arrayGeschw[pos];
    }
 
    pos++;
 
    // --- Alte Zeichen am Ende löschen ---
    int oldLenW = strlen(lastArrayWinkel);
    for (int i = lenW; i < oldLenW; i++)
    {
        lcdGotoXY(18 + i, 2);
        lcdPrintS(" ");
    }
 
    int oldLenG = strlen(lastArrayGeschw);
    for (int i = lenG; i < oldLenG; i++)
    {
        lcdGotoXY(18 + i, 5);
        lcdPrintS(" ");
    }
 
    // --- pos zurücksetzen, wenn beide Werte fertig gezeichnet ---
    if (pos >= lenW && pos >= lenG)
    {
        pos = 0;
        *ausgabeKomplett = 1;
    }
}
 