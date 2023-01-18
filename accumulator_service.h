#ifndef MASZYNARAM_ACCUMULATOR_SERVICE_H
#define MASZYNARAM_ACCUMULATOR_SERVICE_H

#include "support_functions_and_declarations.h"
#include "input_output_tapes.h"
#include "prompts_and_exceptions.h"


// OBSLUGA AKUMULATORA - DZIAŁANIA NA AKUMULATORZE (MATEMATYCZNE ORAZ LOAD), WYPISANIE Z AKUMULATORA NA WYJSCIE (WRITE)

int acc_arg_service(char arg[]);

bool load_value(char arg[]);
bool add_value(char arg[]);
bool sub_value(char arg[]);
bool mult_value(char arg[]);
bool div_value(char arg[]);
bool write_value(char arg[]);

#endif //MASZYNARAM_ACCUMULATOR_SERVICE_H
