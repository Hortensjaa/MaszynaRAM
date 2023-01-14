#ifndef MASZYNARAM_STREAM_CONTROL_H
#define MASZYNARAM_STREAM_CONTROL_H

#include "support_functions_and_declarations.h"

//bool stream_disabled = false;

void jump_tag(char tag[]); // skok bezwarunkowy
void jzero_tag(char tag[]); // skok, jeśli w akumulatorze znajduje się zero
void jgtz_tag(char tag[]); // skok, jeśli w akumulatorze znajduje się liczba dodatnia
void halt_tag(); // zatrzymanie programu

#endif //MASZYNARAM_STREAM_CONTROL_H
