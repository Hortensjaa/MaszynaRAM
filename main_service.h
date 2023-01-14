#ifndef MASZYNARAM_MAIN_SERVICE_H
#define MASZYNARAM_MAIN_SERVICE_H

#include "memory_service.c"
#include "input_output_tapes.c"
#include "accumulator_service.c"
#include "prompts_and_exceptions.c"
#include "support_functions.c"

// obsluga pamieci
void read(); // czytanie kolejnej liczby z taśmy wejściowej do komorki o numerze i
void store(); // zapisanie wartosci z akumulatora do komórki o numerze i

// obsluga akumulatora
void load(); // przesłanie do akumulatora wartosci
void add(); // +
void sub(); // -
void mult(); // *
void diiv(); // :
void write(); // zapisywanie na taśmie wyjsciowej

// przekierowania
void jump(); // skok bezwarunkowy
bool jzero(); // skok, jeśli w akumulatorze znajduje się zero
bool jgtz(); // skok, jeśli w akumulatorze znajduje się liczba dodatnia
void halt(); // zatrzymanie programu

// wypisywanie stanu
void print_status();

#endif //MASZYNARAM_MAIN_SERVICE_H
