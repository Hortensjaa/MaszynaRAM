#include "stream_control.h"
#include "commands_queue.h"


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
            command_node *b = find_tag_in_queue(tag);
            if (b != NULL) run_command_queue(tag);
            else {
                stream_disabled = true;
                strcpy(tag_on_stack, tag);
            }
        }
    }
}

void jgtz_tag(char tag[]) {
    if (live_mode == true && stream_disabled == false) {
        if (acc > 0) {
            command_node *b = find_tag_in_queue(tag);
            if (b != NULL) run_command_queue(tag);
            else {
                stream_disabled = true;
                strcpy(tag_on_stack, tag);
            }
        }
    }
}


void halt_tag() {
    if (live_mode == true && stream_disabled == false) {
        printf("Koniec dzialania programu :)");
        exit(0);
    }
}
