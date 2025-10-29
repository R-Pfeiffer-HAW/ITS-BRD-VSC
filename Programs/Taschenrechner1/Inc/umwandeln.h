#ifndef UMWANDELN_H
#define UMWANDELN_H

#include <stdbool.h>  // Für bool

// Wandelt eine ganze Zahl in einen String um
// num: Zahl, die umgewandelt werden soll
// str: Puffer, in den der String geschrieben wird
// Rückgabe: Länge des erzeugten Strings
int integer_to_string(int num);

// Gibt einen String rückwärts aus (z. B. auf Display)
// str: String, der angezeigt werden soll
// length: Länge des Strings
void reverse_string(const char str[], int length);

#endif // INTEGER_CONVERT_H