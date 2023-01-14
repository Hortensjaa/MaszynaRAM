#ifndef MASZYNARAM_MEMORY_SERVICE_H
#define MASZYNARAM_MEMORY_SERVICE_H

#include "support_functions_and_declarations.h"
#include "input_output_tapes.h"
#include "prompts_and_exceptions.h"

// OBSLUGA PAMIECI - READ, STORE, OBSLUGA ARGUMENTOW DLA INDEKSOW

int mem_arg_service(char arg[]);

void read_index(char arg[]);
void store_index(char arg[]);

//void read(); // czytanie kolejnej liczby z taśmy wejściowej do komorki o numerze i
//void store(); // zapisanie wartosci z akumulatora do komórki o numerze i

void print_memory();

#endif //MASZYNARAM_MEMORY_SERVICE_H
