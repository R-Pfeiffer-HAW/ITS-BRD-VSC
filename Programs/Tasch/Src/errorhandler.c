
/**
 * @file errorhandler.c
 * @brief Implementierung des Fehlerbehandlungsmoduls.
 * @date Okt 2025
 */

#include "errorhandler.h"
#include "display.h"

/**
 * @brief Behandelt Fehlercodes und gibt entsprechende Fehlermeldungen aus.
 *
 * @param error_code Der Fehlercode, der behandelt werden soll.
 */
void handle_error(int error_code) {
  switch (error_code) {
  case -1:
    setErrMode();
    printStdout("FEHLER: Stack overflow.\n");
    break;
  case -3:
    setErrMode();
    printStdout("FEHLER: Stack underflow bei Addition.\n");
    break;
  case -4:
    setErrMode();
    printStdout("FEHLER: Integer Overflow bei Addition.\n");
    break;
  case -5:
    setErrMode();
    printStdout("FEHLER: Stack underflow bei Subtraktion.\n");
    break;
  case -6:
    setErrMode();
    printStdout("FEHLER: Integer Overflow bei Subtraktion.\n");
    break;
  case -7:
    setErrMode();
    printStdout("FEHLER: Stack underflow bei Multiplikation.\n");
    break;
  case -8:
    setErrMode();
    printStdout("FEHLER: Integer Overflow bei Multiplikation.\n");
    break;
  case -9:
    setErrMode();
    printStdout("FEHLER: Stack underflow bei Division.\n");
    break;
  case -10:
    setErrMode();
    printStdout("FEHLER: Integer-Überlauf bei Division.\n");
    break;
  case -11:
    setErrMode();
    printStdout("FEHLER: Division durch Null.\n");
    break;
  case -12:
    setErrMode();
    printStdout("FEHLER: Stack ist leer.\n");
    break;
  case -13:
    setErrMode();
    printStdout("FEHLER: Stack ist leer.\n");
    break;
  case -14:
    setErrMode();
    printStdout("FEHLER: Stack ist leer.\n");
    break;
  case -15:
    setErrMode();
    printStdout("FEHLER: Stack underflow beim Duplizieren (min. 1 Element benötigt).\n");
    break;
  case -16:
    setErrMode();   
    printStdout("FEHLER: Stack underflow beim Tauschen (min. 2 Elemente benötigt).\n");
    break;
  case -17:
    setErrMode();
    printStdout("FEHLER: Unbekannter Operator.\n");
    break;
  }
}