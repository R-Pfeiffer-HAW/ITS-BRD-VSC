/**
 * @file rechnen.h
 * @author 
 * Esmat Rabaki, Raphael Pfeiffer, HAW Hamburg
 * @date Okt 2025
 * @brief Header-Datei für Rechenoperationen auf Basis von Tokens und Stack.
 */

#ifndef RECHNEN_H
#define RECHNEN_H

#include "token.h"  // Für T_token-Definition

/**
 * Unterstützte Operationen:
 *  - NUMBER: Zahl auf den Stack legen
<<<<<<< HEAD
 *  - PLUS: MINUS, MULT, DIV: Arithmetische Operationen mit Fehlerprüfung
=======
 *  - PLUS, MINUS, MULT, DIV: Arithmetische Operationen mit Fehlerprüfung
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
 *  - PRT: Obersten Wert ausgeben
 *  - CLEAR: Stack löschen
 *  - DOUBLE: Obersten Wert duplizieren
 *  - SWAP: Zwei oberste Werte vertauschen
 * @param token Das Token, das interpretiert werden soll
 * @return 0 bei Erfolg, -1 bei Fehler
 */
int rechnen(T_token token);

#endif // RECHNEN_H
