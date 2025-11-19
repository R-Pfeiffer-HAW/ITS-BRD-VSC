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
#include "rechnen.h"

#include "timer.h"
#include "eingabe.h"
#include <stdint.h>


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

	// Test in Endlosschleife
	while(1) {
		eingabeVerarbeitung();
		uint32_t endZeit = getTimeStamp();
		startSchritte = gibSchrittzahl();

		//differnz Zeit
		uint32_t deltaZeit = endZeit - startZeit; 
		// Wenn die Zeitdifferenz zwischen 250 ms und 500 ms liegt, berechne die Geschwindigkeit und den Drehwinkel
		if (deltaZeit >= 250 && deltaZeit <= 500) 
		{
			aktuellerWinkel = berechneWinkel(startSchritte);
			geschwindigkeit = berechneGeschwindigkeit(letzterWinkel, aktuellerWinkel, startZeit, endZeit);
		}
		startZeit = endZeit;
        letzterWinkel = aktuellerWinkel;
	}
}

// EOF
