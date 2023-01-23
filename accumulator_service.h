#ifndef MASZYNARAM_ACCUMULATOR_SERVICE_H
#define MASZYNARAM_ACCUMULATOR_SERVICE_H

#include "support_functions_and_declarations.h"
#include "input_output_tapes.h"
#include "prompts_and_exceptions.h"


// OBSLUGA AKUMULATORA - DZIAŁANIA NA AKUMULATORZE (MATEMATYCZNE ORAZ LOAD), WYPISANIE Z AKUMULATORA NA WYJSCIE (WRITE)

int acc_arg_service(char arg[]); // funkcja pomocnicza obsługująca wczytywanie argumentów

bool load_value(char arg[]); // LOAD - wczytanie wartości do akumulatora
bool add_value(char arg[]); // ADD - dodanie do wartości akumulatora
bool sub_value(char arg[]); // SUB - odjęcie od wartości akumulatora
bool mult_value(char arg[]); // MULT - pomnożenie wartości akumulatora
bool div_value(char arg[]); // DIV - podzielenie wartosci akumulatora
bool write_value(char arg[]); // WRITE - wypisanie wartości na wyjscie

#endif //MASZYNARAM_ACCUMULATOR_SERVICE_H
