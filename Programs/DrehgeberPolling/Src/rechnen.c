

#include "rechnen.h"
#include <stdint.h>

/**             
* @brief Berechnet den Drehwinkel basierend auf der Schrittzahl.
* @param schritte Die aktuelle Schrittzahl des Drehgebers.
* @return Der berechnete Drehwinkel in Grad.
*/
double berechneWinkel(double schritte)
{
     double schritteProUmdrehung = 1200.0; 
     double drehwinkel = (schritte / schritteProUmdrehung) * 360.0;

    return drehwinkel;
}       

/**
* @brief Berechnet die Drehgeschwindigkeit basierend auf der Änderung der Schrittzahl und der Zeit.
* @param letzterWinkel Der vorherige Winkel.
* @param aktuellerWinkel Der aktuelle Winkel.
* @param alterZeit Die Startzeit in Millisekunden.
* @param aktuellerZeit Die Endzeit in Millisekunden.  
*/
double berechneGeschwindigkeit(double letzterWinkel, double aktuellerWinkel, uint32_t alterZeit, uint32_t aktuellerZeit)
{
    double zeitSekunden = (aktuellerZeit - alterZeit) / 90000000.0; // Millisekunden in Sekunden umrechnen

    double winkel = aktuellerWinkel - letzterWinkel;

    if (zeitSekunden <= 0) {
        return 0; //  Division durch Null
    }

    double schritteProSekunde = winkel / zeitSekunden;
    return schritteProSekunde;
}