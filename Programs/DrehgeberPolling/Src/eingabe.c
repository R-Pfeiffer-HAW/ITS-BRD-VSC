#include "eingabe.h"
#include "stm32f429xx.h"
#include <stdbool.h>
#include <stdint.h>

#define IDR_MASK_PIN_0 (0x01U << (0))
#define IDR_MASK_PIN_1 (0x01U << (1))

// Globale Variablen für den Zustand des Drehgebers

static int aktuellePhase = 0;     // 0 = a, 1 = b, 2 = c, 3 = d
static int letztePhase = 0;
static int richtung = 0;          // 1 = vorwärts, -1 = rückwärts, 0 = keine Änderung
static int schrittZaehler = 0;    // Zählt die Phasenwechsel
static bool fehler = false;       // Wird true, wenn ein ungültiger Übergang erkannt wird



/**
* @brief Liest den Zustand von Pin A des Drehgebers aus.
* @return true, wenn Pin A HIGH ist, sonst false.
*/

bool lesePinA(void)
{
    if (IDR_MASK_PIN_0 == (GPIOA->IDR & IDR_MASK_PIN_0)) {
        return true;
    } else {
        return false;
    } 
}

/**
* @brief Liest den Zustand von Pin B des Drehgebers aus.
* @return true, wenn Pin B HIGH ist, sonst false.
*/
bool lesePinB(void)
{
    if (IDR_MASK_PIN_1 == (GPIOA->IDR & IDR_MASK_PIN_1)) {
        return true;
    } else {
        return false;
    }
}

/**
* @brief Bestimmt die aktuelle Phase anhand der Eingangssignale.
* @param A Zustand von Pin A
* @param B Zustand von Pin B
* @return Die aktuelle Phase (0 = a, 1 = b, 2 = c, 3 = d) oder -1 bei Fehler.
*/
int bestimmePhase(bool A, bool B)
{
    if (!A && !B) return 0;   // Phase a
    if (A && !B)  return 1;   // Phase b
    if (A && B)   return 2;   // Phase c
    if (!A && B)  return 3;   // Phase d
    return -1;                // Fehler
}

/**     
* @brief verarbeitet die Eingangssignale des Drehgebers und aktualisiert die Zustände.
*/
void eingabeVerarbeitung(void)
{       
    bool A = lesePinA();
    bool B = lesePinB();

    letztePhase = aktuellePhase;
    aktuellePhase = bestimmePhase(A, B);



    // Wenn Phase ungültig ist, Fehler setzen
    if (aktuellePhase == -1)
    {
        fehler = true;
        return;
    }



    // Keine Änderung → nichts tun
    if (letztePhase == aktuellePhase)
        return;

    // Phasenübergänge auswerten (nach Tabelle aus der Aufgabe)
    if (letztePhase == 0 && aktuellePhase == 1) {
        // a → b = Vorwärtsbewegung
        richtung = 1;
        schrittZaehler++;
    } 
    else if (letztePhase == 1 && aktuellePhase == 2) {
        // b → c = Vorwärtsbewegung
        richtung = 1;
        schrittZaehler++;
    }    
    else if (letztePhase == 2 && aktuellePhase == 3) {
        // c → d = Vorwärtsbewegung
        richtung = 1;
        schrittZaehler++;
    } 
    else if (letztePhase == 3 && aktuellePhase == 0) {
        // d → a = Vorwärtsbewegung
        richtung = 1;
        schrittZaehler++;
    } 
    else if (letztePhase == 1 && aktuellePhase == 0) {
        // b → a = Rückwärtsbewegung
        richtung = -1;
        schrittZaehler--;
    } 
    else if (letztePhase == 2 && aktuellePhase == 1) {
        // c → b = Rückwärtsbewegung
        richtung = -1;
        schrittZaehler--;
    } 
    else if (letztePhase == 3 && aktuellePhase == 2) {
        // d → c = Rückwärtsbewegung
        richtung = -1;
        schrittZaehler--;
    } 
    else if (letztePhase == 0 && aktuellePhase == 3) {
        // a → d = Rückwärtsbewegung
        richtung = -1;
        schrittZaehler--;
    } 
    else {
        // Alle anderen Übergänge sind ungültig
        fehler = true;
        richtung = 0;
    }
}

/**
* @brief Gibt die aktuelle Drehrichtung zurück.
* @return 1 für Vorwärtsbewegung, -1 für Rückwärtsbewegung, 0 für keine Änderung.
*/      
int gibRichtung(void)
{
    return richtung; // 1 = vorwärts, -1 = rückwärts, 0 = keine Änderung
}
/**         
* @brief Gibt die aktuelle Schrittzahl zurück.
* @return Die aktuelle Schrittzahl
*/  
int gibSchrittzahl(void)
{
    return schrittZaehler;
}

/**
* @brief Gibt an, ob ein Fehler im Drehgeber erkannt wurde.
* @return true, wenn ein Fehler erkannt wurde, sonst false.
*/
bool gibFehler(void)
{
    return fehler;
}


