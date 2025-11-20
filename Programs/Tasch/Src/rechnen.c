/**
  * @file rechnen.c
  * @author Esmat Rabaki, Raphael Pfeiffer
  * @date Okt 2025
  * @brief Dieses Modul stellt eine einfache Stack-Verwaltung für Ganzzahlen bereit.
  * Es unterstützt grundlegende Operationen wie push, pop, peek, 
  * sowie Zusatzfunktionen wie clear_stack, duplicate, swap und output_entire_stack.
  *
  */
  
#include "stack.h"
#include "token.h"
#include "display.h"
#include <limits.h>
#include "umwandeln.h"


//Fehlercodes
#define OK 0
//PLUS
#define PLUSUNDERFLOW -3
#define PLUSARITHOVERFLOW -4
//MINUS
#define MINUSUNDERFLOW -5
#define MINUSARITHOVERFLOW -6
//MULT
#define MULTUNDERFLOW -7
#define MULTARITHOVERFLOW -8
//DIV
#define DIVUNDERFLOW -9
#define DIVARITHOVERFLOW -10
#define DIVBYZERO -11
//sonstige
#define UNKNOWNOPERATOR -17



/**
 * @brief Führt die im Token  Operation aus.
 *
 * @param token Token, das den Operator und den Wert enthält.
 * @return Bei bei 0 ist es Erfolg, -1 ist dann  Fehler
 */
 
 
int rechnen(T_token token){
    int a, b, result, error;

    switch (token.tok)
    {
        case NUMBER:
            error = push(token.val);
            if (error != OK) 
            {
                return error;
            }
            return OK;

        case PLUS:
            if (pop(&a) != OK || pop(&b) != OK) 
            {
                return PLUSUNDERFLOW;
            }

            // Overflow-Check für Addition
            if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) 
            {
                return PLUSARITHOVERFLOW;
            }
            result = b + a;
            push(result);
            return OK;

        case MINUS:
            if (pop(&a) != OK || pop(&b) != OK)
            {
                return MINUSUNDERFLOW;
            }
            // Overflow-Check für Subtraktion
            if ((a < 0 && b > INT_MAX + a) || (a > 0 && b < INT_MIN + a)) 
            {
                return MINUSARITHOVERFLOW;
            }
            result = b - a;
            push(result);
            return OK;

        case MULT:
            if (pop(&a) != OK || pop(&b) != OK) 
            {
                return MULTUNDERFLOW;
            }
            if (a == 0 || b == 0)     
            {
                return OK; // Kein Overflow
            }
            if ((a > 0 && b > 0 && a > INT_MAX / b) ||
                (a > 0 && b < 0 && b < INT_MIN / a) ||
                (a < 0 && b > 0 && a < INT_MIN / b) ||
                (a < 0 && b < 0 && a < INT_MAX / b)) {
                return MULTARITHOVERFLOW;
            }
            result = b * a;
            push(result);
            return OK;

        case DIV:
            if (pop(&a) != OK || pop(&b) != OK) 
            {
                return DIVUNDERFLOW;
            }
            if (a == INT_MIN && b == -1) 
            {
              return DIVARITHOVERFLOW;
}
            if (a == 0) 
            {
                return DIVBYZERO;
            }
            result = b / a;
            push(result);
            return OK;

        case PRT:
            clearStdout();
            error = peek(&result);
            if (error != OK) {
                return error;  
            }
            setNormalMode();
            integer_to_string(result);
            return OK;

        case PRT_ALL:
        {
            clearStdout();
            int *stack;
            int count;
            
            error = output_entire_stack(&stack, &count);
            if (error != OK) {
                return error;
            }
            setNormalMode();
            for (int i = count - 1; i >= 0; i--) 
            {
                integer_to_string(stack[i]);
            }
            return OK;
        }

        case CLEAR:
            error = clear_stack();
            if (error != OK) {
                return error;
            }
            return OK;

        case DOUBLE:
            clearStdout();
            error = duplicate();
            if (error != OK) 
            {
                return error;
            }
           
            peek(&result);
            setNormalMode();
            integer_to_string(result);
            return OK;

        case SWAP:
            clearStdout();
            error = swap(a, b);
            if (error != OK) 
            {
                return error;
            }
            setNormalMode();
            integer_to_string(a);
            integer_to_string(b);   
            return OK;

        default:
            return UNKNOWNOPERATOR;
    }
}
