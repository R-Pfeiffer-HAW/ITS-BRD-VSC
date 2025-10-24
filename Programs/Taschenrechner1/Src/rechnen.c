/**
  * @file rechnen.c
  * @author Esmat Rabaki, Raphael Pfeiffer, HAW Hamburg 
  * @date Okt 2025
  * @brief This file uses the given operators to execute the correspondig tasks.  
  */
#include "stack.h"
#include "token.h"
#include "display.h"
#include <limits.h>

int rechnen(T_token token)
{
    int a, b, result;

    switch (token.tok)
    {
        case NUMBER:
            if (push(token.val) == -1) {
                setErrMode();
                printStdout("FEHLER: Stack overflow.\n");
                return -1; // Fehler beim Pushen
            }
            return 0;

        case PLUS:
            if (pop(&a) == -1 || pop(&b) == -1) {
                setErrMode();
                printStdout("FEHLER: Stack underflow.\n");
                return -1; // Fehler beim Poppen
            }

            //overflow prüfen
            if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
                setErrMode();
                printStdout("FEHLER: Integer Overflow bei Addition.\n");
                return -1; // Overflow Fehler
            }
            result = b + a;
            push(result);
            return 0;
            

        case MINUS:
        if (pop(&a) == -1 || pop(&b) == -1) {
            setErrMode();
            printStdout("FEHLER: Stack underflow.\n");
            return -1; // Fehler beim Poppen
        }

        //overflow prüfen
        if ((a < 0 && b > INT_MAX + a) || (a > 0 && b < INT_MIN + a)) {
            setErrMode();
            printStdout("FEHLER: Integer Overflow bei Addition.\n");
            return -1; // Overflow Fehler
        }
        result = b - a;
        push(result);
        return 0;
        

        case MULT:
            if (pop(&a) == -1 || pop(&b) == -1) {
                setErrMode();
                printStdout("FEHLER: Stack underflow.\n");
                return -1; // Fehler beim Poppen
            }
            result = b * a;
            push(result);
            return 0;


        case DIV:
            if (pop(&a) == -1 || pop(&b) == -1) {
                setErrMode();
                printStdout("FEHLER: Stack underflow.\n");
                return -1; // Fehler beim Poppen
            } 
            else if (a == 0) {
                setErrMode();
                printStdout("FEHLER: Division durch Null.\n");
                return -1; // Division durch Null Fehler
            }
            else {
                result = b / a;
                push(result);
                return 0;
            }

        case PRT:
            pop( &a);
            printStdout("Top of Stack: ");
            char buffer[12];
            sprintf(buffer, "%d\n", a);
            printStdout(buffer);
            push(a); // Wert wieder auf den Stack legen
            return 0;


        case CLEAR:
            clear_stack();
            return 0;

        case DOUBLE:
            duplicate();
            return 0;

        case SWAP:
            swap(); 
            return 0;

        default:
            return -1; // Return an error code for unknown operators
    }
}
