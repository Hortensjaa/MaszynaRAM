#include "commands_queue.h"

// OBSŁUGA KOLEJKI KOMEND

// wskaźnik na głowę linii komend ustawiamy początkowo na NULL
struct command_node *command_head = NULL;

// funkcja pomocnicza, tworząca nową węzeł reprezentujący komendę command o argumencie arg i etykiecie tag
command_node* new_command_node(char command[], char arg[], char tag[]) {
    // alokowanie pamięci na nowy węzeł
    command_node* new = (struct command_node*) malloc(sizeof(struct command_node));
    // przypisanie wartości atrybutom
    strcpy(new->command, command);
    strcpy(new->arg, arg);
    strcpy(new->tag, tag);
    new->next = NULL;
    return new; // zwrócenie wskaźnika
}

// dodanie nowej komendy do kolejki
command_node* insert_command_node(char command[], char arg[], char tag[]) {
    command_node* new = new_command_node(command, arg, tag); // tworzenie nowego węzła
    // dodanie nowego węzła na koniec kolejki
    if (command_head == NULL) {
        command_head = new;
        return command_head;
    }
    command_node* cur = command_head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = new;
    return command_head;
}

// szukanie komendy w "słowniku"
int find_in_names_arr(char command[]) {
    for (int i  = 0; i < COMMANDS_NUMBER; i++){
        // jeśli komenda jest na liście, zwracam indeks jej wystąpienia
        if (equal_string(command, names_arr[i])) return i;
    }
    return -1; // jeśli komendy nie ma na liście, zwracam -1
}

// wywoływanie komendy z kolejki
void run_command(command_node* node) {
    // HALT jest obsługiwany osobno, ponieważ jest jedyną operacją bezargumentową
    if (equal_string(node->command, "HALT")) halt_tag("\0");
    // odwołanie do słownika, łączącego komendę z maszyny RAM z funkcją w programie, odpowiadającą jej wykonaniu
    else {
        int fun_arr_index = find_in_names_arr(node->command);
        (*fun_ptr_arr[fun_arr_index])(node->arg);
    }
}

// szukanie w kolejce komendy pod określoną etykietą
// przejście po kolejnych elementach kolejki, dopóki nie trafimy na etykietę tag
command_node* find_tag_in_queue(char tag[]) {
    if (command_head == NULL) return NULL;
    command_node* cur = command_head;
    while (cur != NULL) {
        // jeżeli znajdziemy etykietę, zwracamy wskaźnik na pozycję w kolejce
        if (equal_string(cur->tag, tag)) return cur;
        cur = cur->next;
    }
    // jeśli nie znajdziemy etykiety, zwracamy NULL
    printf("Nie znaleziono etykiety\n");
    return NULL;
}

// wywoływanie kolejki komend, zaczynając od etykiety tag
bool run_command_queue(char tag[]) {
    if (command_head == NULL) return false;
    command_node* cur = find_tag_in_queue(tag); // szukamy etykiety w kolejce
    if (cur == NULL) return false; // jeżeli nie znaleźliśmy, zwracamy false
    // jeżeli znaleźliśmy etykietę, zaczynając od węzła o wskaźniku cur, wykonujemy każdą operację w kolejce
    while (cur != NULL) {
        run_command(cur);
        cur = cur->next;
    }
    return true; // zwracamy true - wywołanie kolejki się powiodło
}

// każdy węzeł jest wypisywany w postaci "etykieta: KOMENDA('argument') -> "
// lub "KOMENDA('argument') -> ", jeżeli etykiety nie ma
void print_command_node(command_node *node) {
    if (!equal_string(node->tag, TAG_PLACEHOLDER)) printf("%s: ", node->tag);
    printf("%s('%s') -> ", node->command, node->arg);
}

// wypisanie całej kolejki
void print_command_queue() {
    if (command_head == NULL) { printf("\n"); return; }
    command_node* cur = command_head;
    // pętla wypisująca po kolei każdy węzeł
    while (cur != NULL) {
        print_command_node(cur);
        cur = cur->next;
    }
    printf("\n");
}

// zwalnianie pamięci
void freeQueue(command_node *head) {
    struct command_node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
