#include "stream_control.h"


bool stream_disabled = false;
char tag_on_stack[MAX_TAG_LEN] = TAG_PLACEHOLDER;

bool jump_tag(char tag[]) { // przeskocz do danego tagu
    if (stream_disabled == false) {
        command_node *b = find_tag_in_queue(tag);
        if (b != NULL) {
            jump_to_tag_prompt(tag);
            run_command_queue(tag);
        }
        else {
            stream_disable_prompt(tag);
            stream_disabled = true;
            strcpy(tag_on_stack, tag);
        }
    }
    return true;
}

bool jzero_tag(char tag[]) {
    if (stream_disabled == false) {
        if (acc == 0) {
            command_node *b = find_tag_in_queue(tag); // szukam etykiety w juz istniejacym kodzie
            if (b != NULL) { // etykieta znaleziona - wykonuje kod od niej
                jump_to_tag_prompt(tag);
                run_command_queue(tag);
            }
            else { // etykieta nie znaleziona - blokuje strumien
                stream_disable_prompt(tag);
                stream_disabled = true;
                strcpy(tag_on_stack, tag);
            }
        }
        else condition_false_prompt();
    }
    return true;
}

bool jgtz_tag(char tag[]) {
    if (stream_disabled == false) {
        if (acc > 0) {
            command_node *b = find_tag_in_queue(tag);
            if (b != NULL) {
                jump_to_tag_prompt(tag);
                run_command_queue(tag);
            }
            else {
                stream_disable_prompt(tag);
                stream_disabled = true;
                strcpy(tag_on_stack, tag);
            }
        }
        else condition_false_prompt();
    }
    return true;
}

bool halt_tag(char placeholder[]) {
    if (stream_disabled == false) {
        if (live_mode) printf("Koniec dzialania programu :)");
        else print_status();
        exit(0);
    }
    printf("%s", placeholder); // TODO: da sie to jakos ladniej, zeby nie rzucalo bledu?
    return true;
}


