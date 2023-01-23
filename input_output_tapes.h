#ifndef MASZYNARAM_INPUT_OUTPUT_TAPES_H
#define MASZYNARAM_INPUT_OUTPUT_TAPES_H

#include "support_functions_and_declarations.h"

// OBSLUGA TASM WEJSCIA/WYJSCIA

// struct reprezentujacy liczbe na tasmie
typedef struct tape_node {
    int data;
    struct tape_node* next;
} tape_node;

// wskaznik na poczatek tasmy wejsciowej
extern struct tape_node* input_head;
// wskaznik na poczatek tasmy wyjsciowej
extern struct tape_node* output_head;

// dodanie elementu na koniec taśmy
tape_node* insert_tape(int value, tape_node **head);
// usunięcie (do wczytania) głowy z taśmy wejściowej
tape_node* delete_input_tape();

// wypisanie stanu taśmy; argumentem powinien być char 'i' lub 'o'
void print_tape(tape_node *head);

#endif //MASZYNARAM_INPUT_OUTPUT_TAPES_H
