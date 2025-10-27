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
#include <stdio.h>


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

        case PLUS: {
            int ra, rb;
            ra = pop(&a);
            rb = (ra == 0) ? pop(&b) : -1;
            if (ra == -1 || rb == -1) {
                if (ra == 0) (void)push(a);
                setErrMode();
                printStdout("FEHLER: Stack underflow.\n");
                return -1;
            }
            // Overflow-Check Addition
            if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
                setErrMode();
                printStdout("FEHLER: Integer Overflow bei Addition.\n");
                (void)push(b); (void)push(a); // Zustand wiederherstellen optional
                return -1;
            }
            result = b + a;
            if (push(result) == -1) {
                setErrMode();
                printStdout("FEHLER: Stack overflow.\n");
                return -1;
            }
            return 0;
        }
            
            

        case MINUS: {
            int ra, rb;
            ra = pop(&a);
            rb = (ra == 0) ? pop(&b) : -1;
            if (ra == -1 || rb == -1) {
                if (ra == 0) (void)push(a);
                setErrMode();
                printStdout("FEHLER: Stack underflow.\n");
                return -1;
            }
            // Overflow-Check Subtraktion: b - a
            if ((a > 0 && b < INT_MIN + a) || (a < 0 && b > INT_MAX + a)) {
                setErrMode();
                printStdout("FEHLER: Integer Overflow bei Subtraktion.\n");
                (void)push(b); (void)push(a);
                return -1;
            }
            result = b - a;
            if (push(result) == -1) {
                setErrMode();
                printStdout("FEHLER: Stack overflow.\n");
                return -1;
            }
            return 0;
        }
        

        case MULT: {
            int ra, rb;
            ra = pop(&a);
            rb = (ra == 0) ? pop(&b) : -1;
            if (ra == -1 || rb == -1) {
                if (ra == 0) (void)push(a);
                setErrMode();
                printStdout("FEHLER: Stack underflow.\n");
                return -1;
            }
            result = b * a;
            if (push(result) == -1) {
                setErrMode();
                printStdout("FEHLER: Stack overflow.\n");
                return -1;
            }
            return 0;
        }


        case DIV: {
            int ra, rb;
            ra = pop(&a);
            rb = (ra == 0) ? pop(&b) : -1;
            if (ra == -1 || rb == -1) {
                if (ra == 0) (void)push(a);
                setErrMode();
                printStdout("FEHLER: Stack underflow.\n");
                return -1;
            }
            if (a == 0) {
                setErrMode();
                printStdout("FEHLER: Division durch Null.\n");
                (void)push(b); (void)push(a);
                return -1;
            }
            result = b / a;
            if (push(result) == -1) {
                setErrMode();
                printStdout("FEHLER: Stack overflow.\n");
                return -1;
            }
            return 0;
        }

        case PRT: {
            if (pop(&a) == -1) {
                setErrMode();
                printStdout("FEHLER: Stack ist leer.\n");
                return -1;
            }
            printStdout("Top of Stack: ");
            char buffer[12];
            sprintf(buffer, "%d\n", a);
            printStdout(buffer);
            (void)push(a); // zurücklegen
            return 0;
        }

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
