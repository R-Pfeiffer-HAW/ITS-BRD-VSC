


#include "ausgabeLEDs.h"
#include <stdint.h>

#include "stm32f4xx_hal.h"

#define BSRR_MASK_PIN_23 (0x01U << 7)
#define BSRR_MASK_PIN_22 (0x01U << 6)



/**
 * @brief Schaltet die LEDs entsprechend der übergebenen Maske ein oder aus.
 * @param led_mask Bitmaske, die angibt, welche LEDs geschaltet werden sollen.
 */
void toggle_LEDs(uint8_t led_mask, int richtung) 
{
    GPIOD->BSRR = (0x01 << (led_mask));

    if (richtung ==1)
    {
        GPIOE->BSRR = BSRR_MASK_PIN_23; // LED 23 anschalten (vorwärts)
        GPIOE->BSRR = (BSRR_MASK_PIN_22 << 2); // LED 22 ausschalten

    }else {
        GPIOE->BSRR = BSRR_MASK_PIN_22; // LED 22 anschalten (rückwärts)
        GPIOE->BSRR = (BSRR_MASK_PIN_23 << 1); // LED 23 anschalten (vorwärts)
    }

}   



