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
		HAL_Delay(100);
		bool s6 = readGPIOPIN();
		// wenn taste s6 gedrückt ist, geh rein und setzte alle Variablen zurück
		if(s6 == true)
		{
			fehlerZuruecksetzen();
			lcdPrintS("allles würde zurückgesetzt");
		}
		// wenn ein fehler bei der phase auftretet, berechne nix  
		if (gibFehler() == false)
		{
			lcdPrintS("kein Fehler");
		}
	}
}

// EOF
