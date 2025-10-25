
#include <stdbool.h> // Für den booleschen Wert
#include "display.h"





//String umkehren
void reverse_string(char str[], int length) {
    for (int t = length - 1; t >= 0; t--) {
        printToEchoLine(str[t]); // Dein Display-Ausgabebefehl
    }
}

int integer_to_string(int num) {

    char str[12];  
    int i = 0;
    bool negative = false;
    
     // 1. Sonderfall Null
    if (num == 0) {
        str[i++] = '0';   //Konvertiere die Ziffer
        str[i] = '\0';    //String-Ende
        reverse_string(str, i);
        return 0;
    }   

    // Sonderfall negative Zahlen (optional, aber empfohlen)
    if (num < 0) {
        negative = true;
        num = -num; // Arbeite mit dem positiven Wert
    }
   

    while (num != 0 ) {
        int digit = num % 10;
        str[i++] = digit + '0';
         num = num / 10;  // Entfernt die letzte Ziffer
    
    }

    //Füge das Minuszeichen hinzu, falls nötig
    if (negative) {
        str[i++] = '-';
    }

    //String-Ende (Null-Terminator)
    str[i] = '\0';
 
    // String umkehren, da Ziffern in umgekehrter Reihenfolge gespeichert wurden
    reverse_string(str, i);
    return i;

}


