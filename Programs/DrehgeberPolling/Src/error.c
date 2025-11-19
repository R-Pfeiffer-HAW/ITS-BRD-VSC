

#include "eingabe.h"

void fehlerZuruecksetzen(void)
{
    fehler = false;        // Fehlerflag löschen
    richtung = 0;          // Richtung neutralisieren (optional)
    letztePhase = aktuellePhase; // Damit kein direkt neuer Fehler entsteht
    
}