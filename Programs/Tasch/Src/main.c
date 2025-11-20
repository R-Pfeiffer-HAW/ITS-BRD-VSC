/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

//#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
//#include "lcd.h"
#include "display.h"
//#include "fontsFLASH.h"
//#include "additionalFonts.h"
//#include "error.h"
#include "scanner.h"
#include "token.h"
#include "rechnen.h"
#include "errorhandler.h"


int main(void)
{
    initITSboard();                        // Initialisierung des ITS Boards
    GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
    TP_Init(false);                       // Initialisierung des LCD Boards mit Touch

    initDisplay();
    
    // Test in Endlosschleife
    while(1) {
      int error_code;
      T_token t = nextToken();
      error_code = rechnen(t);
      handle_error(error_code);
    }
    // return 0; // nicht erreicht
}