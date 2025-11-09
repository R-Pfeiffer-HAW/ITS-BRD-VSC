

#include "rechnen.h"

/**             
* @brief Berechnet den Drehwinkel basierend auf der Schrittzahl.
* @param schritte Die aktuelle Schrittzahl des Drehgebers.
* @return Der berechnete Drehwinkel in Grad.
*/
double berechneWinkel(double schritte)
{
     int schritteProUmdrehung = 1200; 
     double drehwinkel = (schritte / schritteProUmdrehung) * 360.0;

    return drehwinkel;
    
}       

/**
* @brief Berechnet die Drehgeschwindigkeit basierend auf der Änderung der Schrittzahl und der Zeit.
* @param alteSchritte Die vorherige Schrittzahl.
* @param neueSchritte Die aktuelle Schrittzahl.
* @param startZeit Die Startzeit in Millisekunden.
* @param endZeit Die Endzeit in Millisekunden.  
*/
double berechneGeschwindigkeit(double alteSchritte, double neueSchritte, double startZeit, double endZeit)
{
    double zeitSekunden = (endZeit - startZeit) / 1000.0; // Millisekunden in Sekunden umrechnen

    double schritte = neueSchritte - alteSchritte;

    if (zeitSekunden <= 0) {
        return 0; //  Division durch Null
    }

    double schritteProSekunde = schritte / zeitSekunden;
    return schritteProSekunde;
}