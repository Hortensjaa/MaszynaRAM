#ifndef MASZYNARAM_MEMORY_SERVICE_H
#define MASZYNARAM_MEMORY_SERVICE_H

#include "support_functions_and_declarations.h"
#include "input_output_tapes.h"
#include "prompts_and_exceptions.h"

// OBSLUGA PAMIECI - READ, STORE, OBSLUGA ARGUMENTOW DLA INDEKSOW

// obsługa argumentów dla operacji READ oraz STORE
int mem_arg_service(char arg[]);

bool read_index(char arg[]); // READ - wczytanie liczby z taśmy wejściowej do komórki pamięci
bool store_index(char arg[]); // STORE - wpisanie wartości akumulatora do komórki pamięci

// wypisywanie stanu (zajętych komórek) pamięci
void print_memory();

#endif //MASZYNARAM_MEMORY_SERVICE_H
