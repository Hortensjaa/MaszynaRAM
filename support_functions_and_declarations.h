#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define MEMORY_SIZE 1000
#define MAX_ARG_LEN 4 // ((int)log10((double)MEMORY_SIZE) + 1)
#define MAX_TAG_LEN 50
#define MAX_COMMAND_LEN 6
#define COMMANDS_NUMBER 12
#define PRINT_LINE "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
#define PRINT_LINE_DISABLED "- - - - - - - - - STREAM - DISABLED - - - - - - - - -\n"
#define TAG_PLACEHOLDER "<placeholder>"

// TODO: zapisywanie kodu do pliku?
// TODO: tryb wpisywania instrukcji i wykonywania po skonczeniu

int acc; // akumulator
int memo[MEMORY_SIZE]; // pamiec
bool live_mode; // wybor trybu
char tag_on_stack[MAX_TAG_LEN]; // tag, na ktory czekam, jesli strumien jest zablokowany

bool equal_string(const char* string1, const char* string2);
int pot(int a, int b);

#endif // DECLARATIONS_H
