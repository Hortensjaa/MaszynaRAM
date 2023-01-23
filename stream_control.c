#include "stream_control.h"

// OBSŁUGA SKOKOW I STRUMIENIA INSTRUKCJI

// początkowo strumień nie jest zablokowany
bool stream_disabled = false;
// początkowo nie szukamy żadnej etykiety, więc ustawiamy wartośc na zdefiniowany placeholder
char tag_on_stack[MAX_TAG_LEN] = TAG_PLACEHOLDER;

// JUMP - skok do komendy o etykiecie tag
bool jump_tag(char tag[]) {
    // robimy cokolwiek tylko, jeśli strumień jest odblokowany
    if (stream_disabled == false) {
        // szukamy etykiety tag w aktualnej kolejce komend
        command_node *b = find_tag_in_queue(tag);
        // jeżeli etykieta została znaleziona
        if (b != NULL) {
            jump_to_tag_prompt(tag); // wypisujemy informację o wykonaniu skoku
            run_command_queue(tag); // uruchamiamy kolejkę instrukcji od tagu
        }
        // jeżeli etykieta nie została znaleziona
        else {
            stream_disable_prompt(tag); // wypisujemy informacje o zablokowaniu strumienia
            stream_disabled = true; // blokujemy strumień
            strcpy(tag_on_stack, tag); // zapisujemy etykietę, na którą "czekamy", żeby odblokować strumień
        }
    }
    return true;
}

// kolejne funkcje działają analogicznie, sprawdzając tylko dodatkowo swoje warunki
// JZERO
bool jzero_tag(char tag[]) {
    if (stream_disabled == false) {
        if (acc == 0) { // sprawdzenie warunku
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

// JGTZ
bool jgtz_tag(char tag[]) {
    if (stream_disabled == false) {
        if (acc > 0) { // sprawdzenie warunku
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

void free_memory() {
    freeTape(input_head);
    freeTape(output_head);
    freeQueue(command_head);
}

// HALT
// przekazuję placeholder tylko po to, by móc obsługiwać HALT razem z innymi operacjami, które są jednoargumentowe :/
bool halt_tag(char placeholder[]) {
    if (stream_disabled == false) {
        if (live_mode) printf("Koniec dzialania programu :)");
        else print_status();
        free_memory(); // zwolnienie pamięci
        exit(0); // poprawne zamknięcie programu z kodem 0
    }
    printf("%s", placeholder); // obejście błędu "unused value" :/
    return true;
}


