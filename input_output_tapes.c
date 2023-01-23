#include "input_output_tapes.h"

// OBSLUGA TASM WEJSCIA/WYJSCIA

// poczatek tasmy wejsciowej na początku wskazuje pusty wskaźnik
struct tape_node* input_head = NULL;
// poczatek tasmy wyjsciowej również
struct tape_node* output_head = NULL;

// dodanie elementu na o wartości value koniec taśmy wejściowej lub wyjściowej (o wskaźniku na głowę head)
// klasyczny algorytm dodawania elementu na koniec listy jednokierunkowej
tape_node* insert_tape(int value, tape_node **head) {
    if (*head == NULL) {
        *head = (struct tape_node*) malloc(sizeof(struct tape_node));
        (*head)->data = value;
        (*head)->next = NULL;
        return *head;
    }
    tape_node* cur = *head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = (struct tape_node*) malloc(sizeof(struct tape_node));
    cur->next->data = value;
    cur->next->next = NULL;
    return *head;
}

// usunięcie (do wczytania) głowy z taśmy wejściowej
tape_node* delete_input_tape() {
    tape_node *temp = input_head; // zapamiętujemy wskaźnik na głowę
    input_head = input_head->next; // oznaczamy następnik jako nową głowę
    return temp; // zwracamy wskaźnik, aby móc później wczytac te wartosc operacją read
}

// wypisanie stanu taśmy
void print_tape(tape_node *head) {
    tape_node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
