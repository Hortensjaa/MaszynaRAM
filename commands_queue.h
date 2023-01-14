#ifndef MASZYNARAM_COMMANDS_QUEUE_H
#define MASZYNARAM_COMMANDS_QUEUE_H

#include "support_functions_and_declarations.h"
#include "accumulator_service.h"
#include "memory_service.h"
#include "stream_control.h"

typedef struct command_node { // struct reprezentujacy komende w kolejce
    char command[6];
    char arg[10];
    char tag[MAX_TAG_LEN];
    struct command_node* next;
} command_node;

//struct command_node *labels[10]; // tablica wskaznikow na "głowy" list komend
struct command_node *command_head;

command_node* new_command_node(char command[], char arg[], char tag[]);
command_node* insert_command_node(char command[], char arg[], char tag[]);

void run_command(command_node* node);
command_node* find_tag_in_queue(char tag[]);
bool run_command_queue(char tag[]);

void print_command_node(command_node *node);
void print_command_queue();

#endif //MASZYNARAM_COMMANDS_QUEUE_H
