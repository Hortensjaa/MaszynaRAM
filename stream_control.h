#ifndef MASZYNARAM_STREAM_CONTROL_H
#define MASZYNARAM_STREAM_CONTROL_H

#include "support_functions_and_declarations.h"
#include "commands_queue.h"
#include "prompts_and_exceptions.h"

// OBSŁUGA SKOKÓW I STRUMIENIA INSTRUKCJI

bool jump_tag(char tag[]); // JUMP - skok bezwarunkowy
bool jzero_tag(char tag[]); // JZERO - skok, jeśli w akumulatorze znajduje się zero
bool jgtz_tag(char tag[]); // JGTZ - skok, jeśli w akumulatorze znajduje się liczba dodatnia
bool halt_tag(char placeholder[]); // HALT - zatrzymanie programu

#endif //MASZYNARAM_STREAM_CONTROL_H
