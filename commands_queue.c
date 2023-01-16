#include "commands_queue.h"

struct command_node *command_head = NULL;

// dodawanie instrukcji do kolejki

command_node* new_command_node(char command[], char arg[], char tag[]) {
    command_node* new = (struct command_node*) malloc(sizeof(struct command_node));
    strcpy(new->command, command);
    strcpy(new->arg, arg);
    strcpy(new->tag, tag);
    new->next = NULL;
    return new;
}

command_node* insert_command_node(char command[], char arg[], char tag[]) {
    command_node* new = new_command_node(command, arg, tag);
    if (command_head == NULL) {
        command_head = new;
        return command_head;
    }
    command_node* cur = command_head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = new;
    return command_head;
}

// wykonywanie kolejki

void run_command(command_node* node) {
//    if (!stream_disabled) printf("%s", PRINT_LINE);
    printf("%s", PRINT_LINE_DISABLED);
    printf("Kolejka instrukcji: "); print_command_queue();
    printf("Tasma wejsciowa: "); print_tape('i');
    if (acc != INT_MIN) printf("Akumulator: %d\n", acc);
    else printf("Akumulator: \n");
    printf("Zajete komorki pamieci:\n"); print_memory();
    printf("Tasma wyjsciowa: "); print_tape('o');
    printf("%s", PRINT_LINE);
    if (equal_string(node->command, "READ")) read_index(node->arg);
    else if (equal_string(node->command, "STORE")) store_index(node->arg);
    else if (equal_string(node->command, "LOAD")) load_value(node->arg);
    else if (equal_string(node->command, "WRITE")) write_value(node->arg);
    else if (equal_string(node->command, "ADD")) add_value(node->arg);
    else if (equal_string(node->command, "SUB")) sub_value(node->arg);
    else if (equal_string(node->command, "MULT")) mult_value(node->arg);
    else if (equal_string(node->command, "DIV")) div_value(node->arg);
    else if (equal_string(node->command, "JUMP")) jump_tag(node->arg);
    else if (equal_string(node->command, "JZERO")) jzero_tag(node->arg);
    else if (equal_string(node->command, "JGTZ")) jgtz_tag(node->arg);
    else if (equal_string(node->command, "HALT")) halt_tag("\0");
}

command_node* find_tag_in_queue(char tag[]) {
    if (command_head == NULL) return NULL;
    command_node* cur = command_head;
    while (cur != NULL) {
        if (equal_string(cur->tag, tag)) return cur;
        cur = cur->next;
    }
    printf("Nie znaleziono etykiety\n");
    return NULL;
}

bool run_command_queue(char tag[]) {
    if (command_head == NULL) return false;
    command_node* cur = find_tag_in_queue(tag);
    if (cur == NULL) return false;
    while (cur != NULL) {
        run_command(cur);
        cur = cur->next;
    }
    return true;
}

// wypisywanie kolejki

void print_command_node(command_node *node) {
    if (!equal_string(node->tag, TAG_PLACEHOLDER)) printf("%s: ", node->tag);
    printf("%s('%s') -> ", node->command, node->arg);
}

void print_command_queue() {
    if (command_head == NULL) { printf("\n"); return; }
    command_node* cur = command_head;
    while (cur != NULL) {
        print_command_node(cur);
        cur = cur->next;
    }
    printf("\n");
}
