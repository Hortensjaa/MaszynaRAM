#include "main_service.h"

// ZMIENNE GLOBALNE

bool read_from_file = false; // domyślnie nie wczytujemy danych z pliku
FILE *file = NULL; // domyślnie nie ma pliku do wczytania danych
bool live_mode = true; // domyślnie działamy w trybie krokowym

// "SŁOWNIK" łączący instrukcje maszyny RAM z funkcjami programu
// tablica wskaźników na funkcje, odpowiadające komendom w maszynie RAM
bool (*fun_ptr_arr[COMMANDS_NUMBER])(char*) = {load_value, add_value, sub_value, mult_value, div_value,
                                write_value, store_index,read_index,
                                jump_tag, jzero_tag, jgtz_tag, halt_tag};
// lista komend maszyny RAM
char names_arr[COMMANDS_NUMBER][MAX_COMMAND_LEN] = {"LOAD", "ADD", "SUB", "MULT", "DIV",
                                      "WRITE", "STORE", "READ",
                                      "JUMP", "JZERO", "JGTZ", "HALT"};


// INSTRUKCJE STERUJĄCE CAŁYM PROGRAMEM

// obsługa linii bez tagu postaci "KOMENDA argument" np. "READ 2"
void without_tag_service (char command[]) {
    // wyszukuję komendę w liście komend names_arr
    int fun_arr_index = find_in_names_arr(command);
    // jeżeli nie ma takiej komendy...
    if (fun_arr_index == -1) {
        // na ten moment uznajemy, że wczytana wartość po prostu jest etykietą
        char tag[MAX_TAG_LEN];
        strcpy(tag, command);
        // wczytujemy kolejne słowo
        if (read_from_file == false) scanf("%s", command);
        else fscanf(file, "%s", command);
        // przekazujemy potencjalną komendę i to, co uznaliśmy za etykietę do funkcji obsługującej linie z etykietami
        with_tag_service(command, tag);
    // a jeżeli znaleźliśmy komendę na liście
    } else {
        char tag[MAX_TAG_LEN] = TAG_PLACEHOLDER; // etykiety nie ma, więc zastępujemy ją placeholderem
        char arg[MAX_TAG_LEN];
        if (fun_arr_index != 11) { // halt nie bierze argumentu, więc później obsłużymy go osobno
            // wczytujemy argument
            if (read_from_file == false) scanf("%s", arg);
            else fscanf(file, "%s", arg);
        }
        // jeżeli strumień nie jest zablokowany, będziemy wykonywać komendę
        if (stream_disabled == false) {
            // jeżeli to jest "normalna" komenda, a nie skok...
            if (fun_arr_index <= 7) {
                // próbujemy wykonać komendę (wywołać funkcję) z tablicy fun_ptr_arr z pod indeksu fun_arr_index z argumentem arg
                bool b = (*fun_ptr_arr[fun_arr_index])(arg); // sprawdzamy, czy się udało tzn. czy zostało zwrócone true
                // jeżeli się udało wykonać komendę, dodatejemy ją do kolejki
                if (b) insert_command_node(names_arr[fun_arr_index], arg, tag);
            }
            // skoki sa najpierw dodawane do kolejki, pozniej wykonywane, więc obsługujemy je inaczej
            else {
                insert_command_node(names_arr[fun_arr_index], arg, tag);
                (*fun_ptr_arr[fun_arr_index])(arg);
            }
        }
        // nawet, jeśli strumień jest zablokowany, dodajemy instrukcję do kolejki
        else insert_command_node(names_arr[fun_arr_index], arg, tag);
    }
}

// obsługa linii z tagiem postaci "etykieta KOMENDA argument" np. "petla READ 2"
void with_tag_service(char command[], char tag[]) {
    int fun_arr_index = find_in_names_arr(command); // wyszukujemy komendę w names_arr
    // jeżeli jej nie ma, to znaczy, że zostały wprowadzone niepoprawne dane
    if (fun_arr_index == -1) {invalid_command(); return;}
    // jeżeli strumień jest zablokowany, ale etykieta zgadza się z tą, na którą "czekaliśmy", aby odblokować strumień...
    if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false; // odblokowujemy go
    char arg[MAX_TAG_LEN];
    if (fun_arr_index != 11) { // halt nie bierze argumentu, więc jest obsługiwany osobno
        // wczytujemy argument
        if (read_from_file == false) scanf("%s", arg);
        else fscanf(file, "%s", arg);
    }
    // dalej postępujemy analogicznie, jak w without_tag_service
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

// wypisywanie stanu maszyny RAM - raczej nie wymaga komentarza
void print_status() {
    if (!stream_disabled) printf("%s", PRINT_LINE);
    else printf("%s", PRINT_LINE_DISABLED);
    printf("Kolejka instrukcji: "); print_command_queue();
    printf("Tasma wejsciowa: "); print_tape(input_head);
    if (acc != INT_MIN) printf("Akumulator: %d\n", acc);
    else printf("Akumulator: \n");
    printf("Zajete komorki pamieci:\n"); print_memory();
    printf("Tasma wyjsciowa: "); print_tape(output_head);
    printf("%s", PRINT_LINE);
}
