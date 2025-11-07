/**
 * @file stack.c
 * @author Esmat Rabaki und Raphael Pfeiffer
 * @date Oktober 2025
 * @brief Implementierung eines einfachen Integer-Stacks.
 *
 * Dieses Modul kapselt die Stack-Datenstruktur für Ganzzahlen und bietet 
<<<<<<< HEAD
 * Operationen wie push, pop, peek, clear, duplicate, swap.
=======
 * Operationen wie push, pop, peek, clear, duplicate, swap und Ausgabe aller 
 * Elemente. 
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
 */
 
 
#include "stack.h"
#include "display.h"
<<<<<<< HEAD


=======
#include "umwandeln.h"


/** @brief Maximale Stack-Größe */
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
#define SIZE 10

static int stack[SIZE];
static int top = -1; 

<<<<<<< HEAD
=======
// ------------------------------------------------------------
// Hilfsfunktionen
// ------------------------------------------------------------
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62

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
<<<<<<< HEAD
    {
        return -1;
    }
=======
        return -1;

>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
    stack[++top] = data; 
    return 0;
}

/**
 * @brief Entfernt das oberste Element des Stacks.
<<<<<<< HEAD
=======
 *
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
 * @param data ist das wert was wir von stack holen
 * @return int 0 bei Erfolg, -1 bei Stack Underflow.
 */

int pop(int *data) 
{
    if (isEmpty()) 
<<<<<<< HEAD
    {
        return -1; 
    }
=======
        return -1; 

>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
    *data = stack[top--]; 
    return 0;
}

/**
 * @brief Gibt das oberste Element aus, ohne es zu entfernen.
<<<<<<< HEAD
 *@param data ist das wert was auf dem oberste von stack ist
 * @return int 0 bei Erfolg, -1 wenn der Stack leer ist.
 */

int peek(int *data) 
{
    if (isEmpty()) {
        return -1;
    }
     *data = stack[top]; 
    return 0;
=======
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
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
}

/**
 * @brief Löscht alle Elemente des Stacks.
 */
void clear_stack(void) 
{
    if (isEmpty()) {
<<<<<<< HEAD
        setNormalMode();
=======
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
        printStdout("Stack ist bereits leer.\n");
        return;
    }
    top = -1;
<<<<<<< HEAD
    clearStdout();
=======
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
}

/**
 * @brief Dupliziert das oberste Element des Stacks.
<<<<<<< HEAD
 * @return int 0 bei Erfolg, -1 bei Stack Overflow oder wenn der Stack leer ist.
 */
int duplicate(void) 
{
    if (isEmpty()) {
        return -1;
    }
    int v = stack[top];
    push(v);
    return 0;
=======
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

>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
}

/**
 * @brief Vertauscht die beiden obersten Elemente des Stacks.
<<<<<<< HEAD
 * @return int 0 bei Erfolg, -1 wenn der Stack weniger als zwei Elemente hat.    
 *@param valA ist das oberste wert von stack
 *@param valB ist das zweit oberste wert von stack
 */
int swap(int valA, int valB) 
{
    if (top < 1) 
    {
        return -1;
    }
    valA = stack[top]; 
    valB = stack[top - 1]; 

    stack[top] = valB;
    stack[top - 1] = valA;
    return 0;
=======
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
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
}

/**
 * @brief Gibt den gesamten Inhalt des Stacks auf dem Display aus.
 * 
<<<<<<< HEAD
 * @param stack_data Zeiger auf ein Array, das die Stack-Daten enthält.
 * @param stack_size Zeiger auf eine Variable, die die Größe des Stacks enthält.
 * @return int 0 bei Erfolg, -1 wenn der Stack leer ist.
 */
int output_entire_stack(int **stack_data, int *stack_size)
{
    if (isEmpty()) {

        return -1;
    }
    *stack_data = stack;
    *stack_size = top + 1;
    return 0;
=======
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
>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62
}