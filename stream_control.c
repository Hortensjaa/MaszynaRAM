#include "stream_control.h"


bool stream_disabled = false;
char tag_on_stack[MAX_TAG_LEN] = TAG_PLACEHOLDER;

void jump_tag(char tag[]) { // przeskocz do danego tagu
    if (live_mode == true && stream_disabled == false) {
        command_node *b = find_tag_in_queue(tag);
        if (b != NULL) run_command_queue(tag);
        else {
            stream_disabled = true;
            strcpy(tag_on_stack, tag);
        }
    }
}

void jzero_tag(char tag[]) {
    if (live_mode == true && stream_disabled == false) {
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
        condition_false_prompt();
    }
}

void jgtz_tag(char tag[]) {
    if (live_mode == true && stream_disabled == false) {
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
        condition_false_prompt();
    }
}

void halt_tag() {
    if (live_mode == true && stream_disabled == false) {
        printf("Koniec dzialania programu :)");
        exit(0);
    }
}
