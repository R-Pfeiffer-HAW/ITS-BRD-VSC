/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "ausgabeLEDs.h"
#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "additionalFonts.h"
#include "umwandlungInArray.h"

#include "errorHandler.h"
#include "rechnen.h"
#include "timer.h"
#include "eingabe.h"
#include <stdint.h>



// Zwei Arrays für die Anzeige
char arrayWinkel[6];
char arrayGeschw[6];

// Zustandsvariablen für die sequentielle Ausgabe
int currentArray = 0;   // 0 = Winkel, 1 = Geschwindigkeit
int pos = 0;

// Werte in Arrays packen
void updateArrays(double winkel, double geschw) {
    doubleToCharArray(winkel, arrayWinkel);
    doubleToCharArray(geschw, arrayGeschw);
}



int main(void) {
	initITSboard();    // Initialisierung des ITS Boards
	
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch
	initTimer();                // Timer initialisieren


	double startSchritte;
	double aktuellerWinkel;
	double letzterWinkel = 0.0;
	double geschwindigkeit;
	uint32_t startZeit = getTimeStamp();

	//"Drehwinkel:   Grad und Drehgeschwindigkeit:    Grad/Sek" auf LCD ausgeben
	lcdGotoXY(5, 2);
	lcdPrintS("Drehwinkel:             Grad");
	lcdGotoXY(5, 5);
	lcdPrintS("Winkelgeschw.:            Grad/s");

	// Test in Endlosschleife
	while(1) {

		eingabeVerarbeitung();
		HAL_Delay(100);
		bool s6 = readGPIOPIN();
		// wenn taste s6 gedrückt ist, geh rein und setzte alle Variablen zurück
		if(s6 == true)
		{
			fehlerZuruecksetzen();
			lcdPrintS("zurücksetzen");
		}

		if(gibFehler() == false) {
			uint32_t aktuelleSchritte = gibSchrittzahl();
			uint32_t aktuellerZeit = getTimeStamp();
					// Werte holen
			aktuellerWinkel = berechneWinkel(aktuelleSchritte);
			geschwindigkeit = berechneGeschwindigkeit( letzterWinkel, aktuellerWinkel, startZeit, aktuellerZeit);

			// alten Zustand für näcsten Loop merken
			letzterWinkel = aktuellerWinkel;
			startZeit = aktuellerZeit;

			// Arrays aktualisieren
			updateArrays(aktuellerWinkel, geschwindigkeit);

			// Welches Array wird ausgegeben?
			char* activeArray = (currentArray == 0) ? arrayWinkel : arrayGeschw;

			// Zeile auswählen: Winkel = Zeile 2, Geschwindigkeit = Zeile 5
			int zeile = (currentArray == 0) ? 2 : 5;

			// Eine Stelle ausgeben
			arrayAusgabe(activeArray, pos, zeile);


			// Position erhöhen
			pos++;

			// Wenn Array zu Ende → nächstes Array
			if (pos >= 5) {
				pos = 0;
				currentArray = !currentArray; // 0 ↔ 1 wechseln
		
			}
			lcdGotoXY(10, 10);
			lcdPrintS("       "); // Lösche vorherige Meldung
		} else {
			// Fehlerbehandlung, wenn nötig
			lcdGotoXY(10, 10);
			lcdPrintS("fehler");
		}
	}
}

// EOF

