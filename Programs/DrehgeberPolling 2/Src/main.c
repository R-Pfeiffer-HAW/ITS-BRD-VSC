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

#include "error1.h"
#include "rechnen.h"
#include "timer.h"
#include "eingabe.h"
#include <stdint.h>
#include "display_update.h"
#include <stdbool.h>

int main(void) {
    initITSboard();    // Initialisierung des ITS Boards
    
    GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
    TP_Init(false);                 // Initialisierung des LCD Boards mit Touch
    initTimer();                // Timer initialisieren

    lcdGotoXY(5, 2);
    lcdPrintS("Drehwinkel:             Grad");
    lcdGotoXY(5, 5);
    lcdPrintS("Winkelgeschw.:            Grad/s");

    bool ausgabeKomplett = 1;
    double startSchritte;
    double aktuellerWinkel = 0.0;
    double letzterWinkel = 0.0;
    double geschwindigkeit = 0.0;
    int letztePhase = 0;
    int abgabe = 0;
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
        }
        if (gibFehler() == false)
        {
            uint32_t endZeit = getTimeStamp();
            uint32_t deltaZeit = endZeit - startZeit;

            // Wenn die Zeitdifferenz zwischen 250 ms und 500 ms liegt, berechne die Geschwindigkeit und den Drehwinkel
            if (deltaZeit >= 250)
            {
                startSchritte = gibSchrittzahl();
                int aktuellePhase = gibPhase();
                
                    if(aktuellePhase != letztePhase)
                    {
                        aktuellerWinkel = berechneWinkel(startSchritte);
                        geschwindigkeit = berechneGeschwindigkeit(letzterWinkel, aktuellerWinkel, startZeit, endZeit);
                        letzterWinkel = aktuellerWinkel;
                        letztePhase = aktuellePhase;
                        ausgabeKomplett = 0;
                    }
                
                startZeit = endZeit;
            }
        }        
        updateDisplay( aktuellerWinkel, geschwindigkeit, &ausgabeKomplett);
    }
}

// EOF





