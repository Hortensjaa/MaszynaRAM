#include "stream_control.h"
#include "commands_queue.h"


bool stream_disabled = false;
char tag_on_stack[MAX_TAG_LEN] = TAG_PLACEHOLDER;

void jump_tag(char tag[]) { // przeskocz do danego tagu
    run_command_queue(tag);
//    if (live_mode == true) {
//        command_node* b = find_tag_in_queue(tag);
//        if (b != NULL) run_command_queue(tag); // jezeli mamy juz te etykiete, to dzialamy
//        else { // jezeli nie, to ignorujemy komendy, az na nia nie trafimy
//            stream_disabled = true;
//            strcpy(tag_on_stack, tag);
//        }
//    }
}

// TODO: Naprawic jutro blokowanie strumienia
// TODO: dziwna etykieta się robi przy jgtz - czemu?
void jzero_tag(char tag[]) {
    if (acc == 0) {
        run_command_queue(tag);
    }
//    command_node* b = find_tag_in_queue(tag);
//    if (b != NULL && acc == 0) run_command_queue(tag);
//    else {
//        if (acc == 0) {
//            stream_disabled = true;
//            strcpy(tag_on_stack, tag);
//        }
//    }
}

void jgtz_tag(char tag[]) {
    if (acc > 0) {
        run_command_queue(tag);
    }
//    if (live_mode == true) {
//        command_node* b = find_tag_in_queue(tag);
//        if (b != NULL) run_command_queue(tag);
//        else {
//            if (acc > 0) {
//                stream_disabled = true;
//                strcpy(tag_on_stack, tag);
//            }
//        }
//    }
}

void halt_tag() {
    printf("Koniec dzialania programu :)");
    exit(0);
}
