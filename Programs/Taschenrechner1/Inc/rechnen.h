/**
 * @file rechnen.h
 * @author Esmat Rabaki, Raphael Pfeiffer, HAW Hamburg
 * @date Okt 2025
 * @brief Schnittstelle für die Rechenfunktionen (Stack-Operationen).
 */

 #ifndef RECHNEN_H
 #define RECHNEN_H
 
 #include "token.h"   // für T_token

 
 /**
  * @brief Führt Berechnungen anhand eines Tokens aus.
  *
  * Diese Funktion nimmt ein Token (z. B. Zahl, Operator oder Befehl)
  * und verarbeitet es entsprechend:
  *  - NUMBER → wird auf den Stack gelegt
  *  - PLUS, MINUS, MULT, DIV → Werte vom Stack holen, berechnen, Ergebnis pushen
  *  - PRT → obersten Stackwert ausgeben
  *  - CLEAR, DOUBLE, SWAP → Stack-Operationen
  *
  * @param token  Das aktuelle Token, das berechnet werden soll.
  * @return 0 bei Erfolg, -1 bei Fehler (z. B. Stack underflow, Division durch 0, Overflow)
  */
 int rechnen(T_token token);
 
 #endif // RECHNEN_H
 