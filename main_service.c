#include "main_service.h"

bool live_mode = true;
bool (*fun_ptr_arr[COMMANDS_NUMBER])(char*) = {load_value, add_value, sub_value, mult_value, div_value,
                                write_value, store_index,read_index,
                                jump_tag, jzero_tag, jgtz_tag, halt_tag};
char names_arr[COMMANDS_NUMBER][MAX_COMMAND_LEN] = {"LOAD", "ADD", "SUB", "MULT", "DIV",
                                      "WRITE", "STORE", "READ",
                                      "JUMP", "JZERO", "JGTZ", "HALT"};

// OBSLUGA DWOCH PRZYPADKOW - Z TAGIEM Z PORZODU I BEZ

int find_in_names_arr(char command[]) {
    for (int i  = 0; i < COMMANDS_NUMBER; i++){
        if (equal_string(command, names_arr[i])) return i;
    }
    return -1;
}

void with_tag_service(char command[], char tag[]) {
    int fun_arr_index = find_in_names_arr(command);
    if (fun_arr_index == -1) {invalid_command(); return;}
    if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    char arg[MAX_TAG_LEN];
    if (fun_arr_index != 11) scanf("%s", arg);
    if (stream_disabled == false) {
        if (fun_arr_index <= 7) {
            bool b = (*fun_ptr_arr[fun_arr_index])(arg);
            if (b) insert_command_node(names_arr[fun_arr_index], arg, tag);
        } else {
            insert_command_node(names_arr[fun_arr_index], arg, tag);
            (*fun_ptr_arr[fun_arr_index])(arg);
        }
    }
    else insert_command_node(names_arr[fun_arr_index], arg, tag);
}

void without_tag_service (char command[]) { // prev: int fun_arr_index
    int fun_arr_index = find_in_names_arr(command);
    if (fun_arr_index == -1) {
        char tag[MAX_TAG_LEN];
        strcpy(tag, command);
        scanf("%s", command);
        with_tag_service(command, tag);
    } else {
        char tag[MAX_TAG_LEN] = TAG_PLACEHOLDER;
        char arg[MAX_TAG_LEN];
        if (fun_arr_index != 11) scanf("%s", arg); // halt nie bierze argumentu
        if (stream_disabled == false) {
            if (fun_arr_index <= 7) {
                bool b = (*fun_ptr_arr[fun_arr_index])(arg);
                if (b) insert_command_node(names_arr[fun_arr_index], arg, tag);
            }
            else { // te odpowiedzialne za stream sa najpierw dodawane do kolejki, pozniej wykonywane
                insert_command_node(names_arr[fun_arr_index], arg, tag);
                (*fun_ptr_arr[fun_arr_index])(arg);
            }
        } else insert_command_node(names_arr[fun_arr_index], arg, tag);
    }
}

void print_status() {
    if (!stream_disabled) printf("%s", PRINT_LINE);
    else printf("%s", PRINT_LINE_DISABLED);
    printf("Kolejka instrukcji: "); print_command_queue();
    printf("Tasma wejsciowa: "); print_tape('i');
    if (acc != INT_MIN) printf("Akumulator: %d\n", acc);
    else printf("Akumulator: \n");
    printf("Zajete komorki pamieci:\n"); print_memory();
    printf("Tasma wyjsciowa: "); print_tape('o');
    printf("%s", PRINT_LINE);
}
