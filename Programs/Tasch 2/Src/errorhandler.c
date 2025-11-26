
/**
 * @file errorhandler.c
 * @brief Implementierung des Fehlerbehandlungsmoduls.
 * @date Okt 2025
 */


#include "errorhandler.h"
#include "rechnen.h"
#include "display.h"



void handle_error(int error_code) {
    switch (error_code) {
        case 1:
            printStdout("Fehler: Division durch Null ist nicht erlaubt.\n");
            break;
        case 2:
            printStdout("Fehler: Ungültige Eingabe.\n");
            break;
        default:
            printStdout("Fehler: Unbekannter Fehlercode.\n");
            break;
    }
}