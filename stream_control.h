#ifndef MASZYNARAM_STREAM_CONTROL_H
#define MASZYNARAM_STREAM_CONTROL_H

#include "support_functions_and_declarations.h"
#include "commands_queue.h"
#include "prompts_and_exceptions.h"

bool jump_tag(char tag[]); // skok bezwarunkowy
bool jzero_tag(char tag[]); // skok, jeśli w akumulatorze znajduje się zero
bool jgtz_tag(char tag[]); // skok, jeśli w akumulatorze znajduje się liczba dodatnia
bool halt_tag(char placeholder[]); // zatrzymanie programu

#endif //MASZYNARAM_STREAM_CONTROL_H
