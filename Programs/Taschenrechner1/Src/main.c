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
# include "display.h"
# include "scanner.h"
# include "rechnen.h"
# include "stack.h"
# include "token.h"



int main(void) 
{
  T_token t;   // aktuelles Token
  T_token c;   // Token für CLEAR-Reset
  int rc;      // Rückgabewert von rechnen()


	initITSboard();    // Initialisierung des ITS Boards
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch

	initDisplay();               // Initialisierung der Displayfunktionen
	stack_init();                  // Initialisierung des Stacks

  // Begruessungstext	
	lcdPrintlnS("TESTESTESTESt (c-project)");
	
	// Test in Endlosschleife
	while (1) {
        T_token t = nextToken();     // liefert .tok (char) und ggf. .val

        // ENTER komplett ignorieren (Scanner liefert ihn evtl. als Token)
        if (t.tok == ENTER) {
            continue;
        }

        // Eingabe-Fehler direkt behandeln
        if (t.tok == OVERFLOW || t.tok == UNEXPECTED) {
            setErrMode();
            if (t.tok == OVERFLOW)  printStdout("Eingabe-Overflow\n");
            else                    printStdout("Ungueltige Eingabe\n");

            // Auf CLEAR warten und System resetten
            T_token c;
            do { c = nextToken(); } while (c.tok != CLEAR);
            clear_stack();
            setNormalMode();
            continue;
        }

        // Normale Verarbeitung: rechnen() macht Ausgabe/Fehlertexte selbst
        int rc = rechnen(t);

        if (rc != 0) {
            // Fehlerpfad zentralisieren: auf CLEAR warten, danach Reset
            T_token c;
            do { c = nextToken(); } while (c.tok != CLEAR);
            clear_stack();
            setNormalMode();
        }
    }
    // return 0; // nicht erreicht
}