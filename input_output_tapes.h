#ifndef MASZYNARAM_INPUT_OUTPUT_TAPES_H
#define MASZYNARAM_INPUT_OUTPUT_TAPES_H

#include "support_functions_and_declarations.h"

typedef struct tape_node { // struct reprezentujacy liczbe na tasmie
    int data;
    struct tape_node* next;
} tape_node;

extern struct tape_node* input_head; // poczatek tasmy wejsciowej
extern struct tape_node* output_head; // poczatek tasmy wyjsciowej

void get_input_tape();
tape_node* insert_input_tape(int data);
tape_node* delete_input_tape();
tape_node* insert_output_tape(int data);

void print_tape(char io);

#endif //MASZYNARAM_INPUT_OUTPUT_TAPES_H
