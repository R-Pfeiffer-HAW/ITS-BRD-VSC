#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>   // für bool, true, false

// ============================
// Stack-Konstanten
// ============================
#define STACK_SIZE 10   // maximale Größe des Stacks


// Initialisiert den Stack 
void stack_init(void);



// Legt eine Zahl auf den Stack
// Gibt 0 bei Erfolg, -1 bei Overflow zurück
int push(int value);


int push(int value);int push(int value);int push(int value);int push(int value);

// Holt das oberste Element vom Stack herunter
// Gibt 0 bei Erfolg, -1 bei Underflow zurück
int pop(int *value);

// Schaut das oberste Element an, ohne es zu löschen
// Gibt 0 bei Erfolg, -1 bei leerem Stack zurück
int peek(int *value);

// Löscht den gesamten Stack
void clear_stack(void);

// Dupliziert den obersten Wert
void duplicate(void);

// Vertauscht die beiden obersten Werte
void swap(void);

#endif // STACK_H
