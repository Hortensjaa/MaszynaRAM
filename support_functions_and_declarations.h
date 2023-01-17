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
#define MAX_TAG_LEN 20
#define MAX_COMMAND_LEN 6
#define COMMANDS_NUMBER 12
#define PRINT_LINE "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
#define PRINT_LINE_DISABLED "- - - - - - - - - STREAM - DISABLED - - - - - - - - -\n"
#define TAG_PLACEHOLDER "<placeholder>"


int acc; // akumulator
int memo[MEMORY_SIZE]; // pamiec
bool live_mode; // wybor trybu
bool read_from_file;
char tag_on_stack[MAX_TAG_LEN]; // tag, na ktory czekam, jesli strumien jest zablokowany
bool stream_disabled;
char tag_on_stack[MAX_TAG_LEN];
FILE *file; // plik do odczytywania danych

bool (*fun_ptr_arr[COMMANDS_NUMBER])(char*);
char names_arr[COMMANDS_NUMBER][MAX_COMMAND_LEN];

bool equal_string(const char* string1, const char* string2);
void print_status();

#endif // DECLARATIONS_H
