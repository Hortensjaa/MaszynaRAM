#ifndef MASZYNARAM_ACCUMULATOR_SERVICE_H
#define MASZYNARAM_ACCUMULATOR_SERVICE_H

#include "support_functions_and_declarations.h"
#include "input_output_tapes.h"
#include "prompts_and_exceptions.h"

// OBSLUGA AKUMULATORA - DZIAŁANIA NA AKUMULATORZE (MATEMATYCZNE ORAZ LOAD), WYPISANIE Z AKUMULATORA NA WYJSCIE (WRITE)

int acc_arg_service(char arg[]);

void load_value(char arg[]);
void add_value(char arg[]);
void sub_value(char arg[]);
void mult_value(char arg[]);
void div_value(char arg[]);
void write_value(char arg[]);

#endif //MASZYNARAM_ACCUMULATOR_SERVICE_H
