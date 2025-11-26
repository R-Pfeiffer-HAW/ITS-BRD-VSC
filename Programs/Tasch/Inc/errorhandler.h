/**
* @file errorhandler.h
 * @author Esmat Rabaki und Raphael Pfeiffer
 * @date Oktober 2025
* @brief Header file for error handling functions.
*/


#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#define OK 0
#define STACKOVERFLOW -1
#define STACKUNDERFLOW -2
//PLUS
#define PLUSARITHOVERFLOW -3
//MINUS
#define MINUSARITHOVERFLOW -4
//MULT
#define MULTARITHOVERFLOW -5
//DIV
#define DIVARITHOVERFLOW -6
#define DIVBYZERO -7
//PRT
#define PRTSTACKEMPTY -8
//PRT_ALL
#define PRTALLSTACKEMPTY -9
// clear stack
#define CLEARSTACKEMPTY -10
//DUPLICATE
#define DUPUNDERFLOW -11 
//SWAP
#define SWAPUNDERFLOW -12
//sonstige
#define UNKNOWNOPERATOR -13
void handle_error(int error_code);

#endif // ERRORHANDLER_H
