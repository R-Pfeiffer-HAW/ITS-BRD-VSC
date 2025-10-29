/**
 * @file stack.c
 * @author Esmat Rabaki und Raphael Pfeiffer
 * @date Oktober 2025
 * @brief Implementierung eines einfachen Integer-Stacks.
 *
 * Dieses Modul kapselt die Stack-Datenstruktur für Ganzzahlen und bietet 
 * Operationen wie push, pop, peek, clear, duplicate, swap und Ausgabe aller 
 * Elemente. 
 */
 
 
#include "stack.h"
#include "display.h"
#include "umwandeln.h"


/** @brief Maximale Stack-Größe */
#define SIZE 10

static int stack[SIZE];
static int top = -1; 

// ------------------------------------------------------------
// Hilfsfunktionen
// ------------------------------------------------------------

/**
 * @brief Prüft, ob der Stack voll ist.
 * 
 * @return int 1, wenn der Stack voll ist, sonst 0.
 */
int isFull(void) 
{ 
    return top == SIZE - 1; 
}

/**
 * @brief Prüft, ob der Stack leer ist.
 */
int isEmpty(void) 
{ 
    return top == -1; 
}

/**
 * @brief Fügt ein neues Element oben auf den Stack hinzu.
 *
 * @param data Wert, der auf den Stack gelegt wird.
 * @return int 0 bei Erfolg, -1 bei Stack Overflow.
 */
int push(int data) 
{
    if (isFull()) 
        return -1;

    stack[++top] = data; 
    return 0;
}

/**
 * @brief Entfernt das oberste Element des Stacks.
 *
 * @param data ist das wert was wir von stack holen
 * @return int 0 bei Erfolg, -1 bei Stack Underflow.
 */

int pop(int *data) 
{
    if (isEmpty()) 
        return -1; 

    *data = stack[top--]; 
    return 0;
}

/**
 * @brief Gibt das oberste Element aus, ohne es zu entfernen.
 * Die Ausgabe erfolgt über das Display.
 */

void peek(void) 
{
    if (isEmpty()) {
        printStdout("FEHLER: Stack ist leer.\n");
        return;
    }

    int data = stack[top]; 
    integer_to_string(data); 
}

/**
 * @brief Löscht alle Elemente des Stacks.
 */
void clear_stack(void) 
{
    if (isEmpty()) {
        printStdout("Stack ist bereits leer.\n");
        return;
    }
    top = -1;
}

/**
 * @brief Dupliziert das oberste Element des Stacks.
 */
void duplicate(void) 
{
    if (isEmpty()) {
        printStdout("FEHLER: Stack ist leer, kann nicht duplizieren.\n");
        return;
    }

    int v = stack[top];
    push(v);
    integer_to_string(v); 

}

/**
 * @brief Vertauscht die beiden obersten Elemente des Stacks.
 */
void swap(void) 
{
    if (top < 1) {
        printStdout("FEHLER: Für das Tauschen werden mindestens zwei Elemente benötigt.\n");
        return;
    }

    int valA = stack[top]; 
    int valB = stack[top - 1]; 

    stack[top] = valB;
    stack[top - 1] = valA;
    integer_to_string(valA);
    integer_to_string(valB);
}

/**
 * @brief Gibt den gesamten Inhalt des Stacks auf dem Display aus.
 * 
 * Die Ausgabe erfolgt vom obersten bis zum untersten Element.
 */
void output_entire_stack(void)
{
    if (isEmpty()) {
        printStdout("Stack ist leer.\n");
        return;
    }

    for (int i = top; i >= 0; i--) {
        integer_to_string(stack[i]);
    }
}