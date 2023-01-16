#ifndef MASZYNARAM_MAIN_SERVICE_H
#define MASZYNARAM_MAIN_SERVICE_H

#include "support_functions.c"
#include "memory_service.c"
#include "input_output_tapes.c"
#include "accumulator_service.c"
#include "prompts_and_exceptions.c"
#include "commands_queue.c"
#include "stream_control.c"


// obsluga tagow
void without_tag_service(int fun_arr_index);
void with_tag_service(char tag[], int fun_arr_index);

// obsluga pamieci
void read(int n, ...); // czytanie kolejnej liczby z taśmy wejściowej do komorki o numerze i
void store(int n, ...); // zapisanie wartosci z akumulatora do komórki o numerze i

// obsluga akumulatora
void load(int n, ...); // przesłanie do akumulatora wartosci
void add(int n, ...); // +
void sub(int n, ...); // -
void mult(int n, ...); // *
void diiv(int n, ...); // :
void write(int n, ...); // zapisywanie na taśmie wyjsciowej

// przekierowania
void jump(int n, ...); // skok bezwarunkowy
void jzero(int n, ...); // skok, jeśli w akumulatorze znajduje się zero
void jgtz(int n, ...); // skok, jeśli w akumulatorze znajduje się liczba dodatnia
void halt(int n, ...); // zatrzymanie programu

// wypisywanie stanu
void print_status();

#endif //MASZYNARAM_MAIN_SERVICE_H
