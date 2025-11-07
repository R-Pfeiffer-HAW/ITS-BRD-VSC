
#include "eingabe.h"
#include "stm32f429xx.h"
#include <stdbool.h>

00000000000001
00000000000010

#define IDR_MASK_PIN_0 (0x01U << (0))
#define IDR_MASK_PIN_1 (0x01U << (1))


bool givePinA(void)
{
    return (GPIOA->IDR & IDR_MASK_PIN_0) != 0;
}
bool givePinB(void)
{
    return (GPIOA->IDR & IDR_MASK_PIN_1) != 0;
}


void input_signal(void)
{       
     bool A = givePinA();
     bool B = givePinB();

     if (A && B) {






    // Polling
    
}




    // Funktion zur Verarbeitung von Eingabesignalen
   