#ifndef MASZYNARAM_COMMANDS_QUEUE_H
#define MASZYNARAM_COMMANDS_QUEUE_H

#include "support_functions_and_declarations.h"

typedef struct command_node { // struct reprezentujacy komende w kolejce
    char command[6];
    char arg[10];
    char label[10];
    struct command_node* next;
} command_node;

struct command_node* command_queue_head;

void print_command_node(command_node *node);
void print_command_queue(command_node *head);

#endif //MASZYNARAM_COMMANDS_QUEUE_H
