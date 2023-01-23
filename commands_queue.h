#ifndef MASZYNARAM_COMMANDS_QUEUE_H
#define MASZYNARAM_COMMANDS_QUEUE_H

#include "support_functions_and_declarations.h"
#include "accumulator_service.h"
#include "memory_service.h"
#include "stream_control.h"

// OBSLUGA KOLEJKI KOMEND

// struct reprezentujacy komende w kolejce
typedef struct command_node {
    char command[6]; // komenda maszyny RAM
    char arg[MAX_TAG_LEN]; // argument (pamietamy, że dla skoków argument jest etykietą)
    char tag[MAX_TAG_LEN]; // etykieta
    struct command_node* next; // wskaźnik na następną komendę w kolejce
} command_node;

// wskaźnik na głowę linii komend
extern struct command_node *command_head;

// funkcja pomocnicza, tworząca nowego structa
command_node* new_command_node(char command[], char arg[], char tag[]);
// dodanie nowej komendy do kolejki
command_node* insert_command_node(char command[], char arg[], char tag[]);
// wywoływanie komendy z kolejki
void run_command(command_node* node);
// szukanie w kolejce komendy pod określoną etykietą
command_node* find_tag_in_queue(char tag[]);
// szukanie operacji, która ma zostać wykonana dla określonej komendy, w "słowniku"
int find_in_names_arr(char command[]);
// wywoływanie kolejki komend, zaczynając od etykiety tag
bool run_command_queue(char tag[]);

// wypisywanie komendy
void print_command_node(command_node *node);
// wypisywanie kolejki komend
void print_command_queue();
// zwalnianie pamięci
void freeQueue(command_node *head);



#endif //MASZYNARAM_COMMANDS_QUEUE_H
