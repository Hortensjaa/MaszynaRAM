#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MEMORY_SIZE 1000
#define MAX_ARG_LEN ((int)log10((double)MEMORY_SIZE) + 1)
#define PRINT_LINE "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n"

// TODO: zapisywanie kodu do pliku?
// TODO: tryb wpisywania instrukcji i wykonywania po skonczeniu

int acc; // akumulator
int memo[MEMORY_SIZE]; // pamiec

bool equal_string(const char* string1, const char* string2);
int pot(int a, int b);

#endif // DECLARATIONS_H
