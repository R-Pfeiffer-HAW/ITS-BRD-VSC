/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "additionalFonts.h"
#include "error.h"


#include "timer.h"
#include "eingabe.h"
#include "rechnen.h"


int main(void) {
	initITSboard();    // Initialisierung des ITS Boards
	
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch
	initTimer();                // Timer initialisieren

	double startZeit = getTimeStamp();
	double startSchritte = gibSchrittzahl();

	// Test in Endlosschleife
	while(1) {

		eingabeVerarbeitung();
		// abfrage für 250ms und 500ms  einfügen


		double endZeit = getTimeStamp();
		double endSchritte = gibSchrittzahl();

		double drehwinkel = berechneDrehwinkel(endSchritte);
		double geschwindigkeit = berechneDrehgeschwindigkeit(startSchritte, endSchritte, startZeit, endZeit);



		startZeit = endZeit;
        startSchritte = endSchritte;
	}
}

// EOF
