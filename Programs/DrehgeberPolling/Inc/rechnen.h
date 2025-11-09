#ifndef RECHNEN_H
#define RECHNEN_H




#include <stdbool.h>

/** 
* @brief Berechnet den Drehwinkel basierend auf der Schrittzahl.
* @param schritte Anzahl der Schritte (Phasenwechsel)
* @return Drehwinkel in Grad
*/
double berechneDrehwinkel(int schritte);


/** 
* @brief Berechnet die Drehgeschwindigkeit in Schritten pro Sekunde.
* @param alteSchritte Schrittzahl zu Beginn des Zeitintervalls
* @param neueSchritte Schrittzahl am Ende des Zeitintervalls
* @param startZeit Startzeit in Millisekunden
* @param endZeit Endzeit in Millisekunden
* @return Drehgeschwindigkeit in Schritten pro Sekunde
*/
double berechneDrehgeschwindigkeit(double alteSchritte, double neueSchritte, double startZeit, double endZeit);

#endif