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

#define IDR_MASK_PIN_0 (0x01U << (0))
#define IDR_MASK_PIN_1 (0x01U << (1))
#define BSRR_MASK_PIN_6 (0x01U << 0)

int main(void) {
	initITSboard();    // Initialisierung des ITS Boards
	
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch

  // Begruessungstext	
	lcdPrintlnS("Hallo liebes TI-Labor (c-project)");

	
	// Test in Endlosschleife
	while(1) {
		for (int i = 0 ; i< 16 ; i++) {
				GPIOD->BSRR = (0x01 << (i));
				HAL_Delay(500);
		}


	}
}

// EOF
