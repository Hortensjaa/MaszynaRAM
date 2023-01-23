#ifndef MASZYNARAM_MAIN_SERVICE_H
#define MASZYNARAM_MAIN_SERVICE_H

// zaincludowanie wszystkich plików nagłówkowych
#include "support_functions_and_declarations.h"
#include "memory_service.h"
#include "input_output_tapes.h"
#include "accumulator_service.h"
#include "prompts_and_exceptions.h"
#include "commands_queue.h"
#include "stream_control.h"

// INSTRUKCJE STERUJĄCE CAŁYM PROGRAMEM

// obsługa linii bez tagu "KOMENDA argument"
void without_tag_service (char command[]);
// obsługa linii z tagiem postaci "etykieta KOMENDA argument"
void with_tag_service(char command[], char tag[]);

// wypisywanie stanu maszyny RAM
void print_status();

#endif //MASZYNARAM_MAIN_SERVICE_H
