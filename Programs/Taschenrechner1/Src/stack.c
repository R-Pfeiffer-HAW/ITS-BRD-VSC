#include "stack.h"
#include "display.h"

// 1. Definition der Stack-Größe
#define SIZE 10

int stack[SIZE];
int top = -1;



// Prüft, ob der Stack voll ist
int isFull(void) 
{ 
    return top == SIZE ; 
}

// Prüft, ob der Stack leer ist
int isEmpty(void) 
{ 
    return top == -1; 
}


/**
 * Fügt ein Element zum Stack hinzu .
 @param zahl wird auf stack gepackt
 */
int push(int data) 
{
  if (isFull()) {
    printStdout("Stack overflow. Stack ist voll\n");
    return -1;
  }
  stack[top++] = data; // Element speichern
}




/**
 * Entfernt und gibt das oberste Element zurück .
 * @param gibt -1 oder einen definierten Fehlerwert bei Underflow zurück.
 */

int pop(int *data) 
{
  if (isEmpty()) {
    printStdout("FEHLER: Stack Underflow! Stack ist leer.\n");
    return -1; // Fehlerwert
  }

   *data = stack[top--]; // Wert des obersten Elements speichern
  return 0;
}


/**
 * Gibt das oberste Element zurück, ohne es zu entfernen (Peek).
 * Gibt -1 oder einen definierten Fehlerwert bei leerem Stack zurück.
 */
int peek(int *data) {
    if (isEmpty()) {
        printStdout("FEHLER: Stack ist leer.\n");
        return -1; // Fehlerwert
    }
   *data = stack[top]; // Wert des obersten Elements speichern
  return 0;
}

void clear_stack(void) {
    if (isEmpty()) {
        printStdout("Stack ist bereits leer.\n");
        return;
    }
    
    // Wir iterieren von top bis zum untersten belegten Index (0)
    for (int i = 0; i <= top; i++) {
        stack[i] = 0; // Setzt den Wert auf 0 (oder einen anderen Marker)
    }
    
    // Löschen des Stacks
    top = -1; 
    
}

void duplicate(void) {
    if (isEmpty()) 
    {
        printStdout("FEHLER: Stack ist leer, kann nicht duplizieren.\n");
        return;
    }

    // 1. Wert abrufen 
    int duplicate = stack[top]; 
    
    // 3. Wert noch einmal pushen (top wird inkrementiert und der Wert gespeichert)
    push(duplicate); 
    printStdout("Oberster Wert %d dupliziert.\n" );
}

void swap(void) 
{
    if (top < 1) { // Benötigt mindestens zwei Elemente
        printStdout("FEHLER: Für das Tauschen werden mindestens 2 Elemente benötigt.\n");
        return;
    }
    
    // 1. Das nächstoberste Element (A) 
    int valA = stack[top]; 
    
    // 2. Das oberste Element (B) 
    int valB = stack[top - 1]; 

    stack[top] = valB;
    stack[top - 1] = valA;
 
}
