#ifndef MASZYNARAM_MAIN_SERVICE_H
#define MASZYNARAM_MAIN_SERVICE_H

#include "support_functions_and_declarations.h"
#include "memory_service.h"
#include "input_output_tapes.h"
#include "accumulator_service.h"
#include "prompts_and_exceptions.h"
#include "commands_queue.h"
#include "stream_control.h"


void with_tag_service(char command[], char tag[]);
void without_tag_service (char command[]);

// wypisywanie stanu
void print_status();

#endif //MASZYNARAM_MAIN_SERVICE_H
