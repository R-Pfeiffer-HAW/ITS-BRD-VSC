/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "display.h"
#include "scanner.h"
#include "token.h"
#include "rechnen.h"


int main(void)
{
    initITSboard();                        // Initialisierung des ITS Boards
    GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
    TP_Init(false);                       // Initialisierung des LCD Boards mit Touch

    initDisplay();
    
    // Test in Endlosschleife
    while(1) {

      T_token t = nextToken();
      rechnen(t);
    }
    // return 0; // nicht erreicht
}