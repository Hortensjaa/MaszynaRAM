#include "support_functions_and_declarations.h"


// funkcja pomocnicza sprawdzająca, czy stringi są jednakowe, ignorująca wielkość liter

bool equal_string(const char* string1, const char* string2) {
    int i = 0;
    while (string1[i] != '\0' || string2[i] != '\0') {
        if (tolower(string1[i]) != tolower(string2[i])) return false;
        i++;
    }
    return true;
}

