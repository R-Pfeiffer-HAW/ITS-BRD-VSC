#ifndef RECHNEN_H
#define RECHNEN_H




#include <stdbool.h>
#include <stdint.h>

/** 
* @brief Berechnet den Drehwinkel basierend auf der Schrittzahl.
* @param schritte Anzahl der Schritte (Phasenwechsel)
* @return Drehwinkel in Grad
*/
double berechneWinkel(double schritte);


/**
* @brief Berechnet die Drehgeschwindigkeit basierend auf der Änderung der Schrittzahl und der Zeit.
* @param letzterWinkel Der vorherige Winkel.
* @param aktuellerWinkel Der aktuelle Winkel.
* @param alterZeit Die Startzeit in Millisekunden.
* @param aktuellerZeit Die Endzeit in Millisekunden.  
*/
double berechneGeschwindigkeit(double letzterWinkel, double aktuellerWinkel, uint32_t alterZeit, uint32_t aktuellerZeit);
#endif