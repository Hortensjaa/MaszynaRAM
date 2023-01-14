#include "input_output_tapes.h"

// OBSLUGA TASM WEJSCIA/WYJSCIA

struct tape_node* input_head = NULL; // poczatek tasmy wejsciowej
struct tape_node* output_head = NULL; // poczatek tasmy wyjsciowej


// wczytanie danych do wejscia
void get_input_tape() {
    int n;
    printf("Podaj, ile liczb pojawi sie na tasmie wejsciowej:\n");
    scanf("%d", &n);
    int input;
    printf("Wprowadz zawartosc tasmy wejsciowej (liczby calkowite rodzielone spacjami):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        insert_input_tape(input);
    }
}

// dodanie nowego elementu do wejscia
tape_node* insert_input_tape(int data) {
    tape_node* new = (struct tape_node*) malloc(sizeof(struct tape_node));
    new->data = data;
    new->next = NULL;
    if (input_head == NULL) {
        input_head = new;
        return input_head;
    }
    tape_node* cur = input_head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = new;
    return input_head;
}

// usuniecie elementu z wejscia
tape_node* delete_input_tape() {
    tape_node *temp = input_head;
    input_head = input_head->next;
    return temp;
}

// dodanie nowego elementu na wyjscie
tape_node* insert_output_tape(int data) {
    tape_node* new = (struct tape_node*) malloc(sizeof(struct tape_node));
    new->data = data;
    new->next = NULL;
    if (output_head == NULL) {
        output_head = new;
        return output_head;
    }
    tape_node* cur = output_head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = new;
    return output_head;
}

// wypisywanie danych
void print_tape(char io) {
    tape_node* temp;
    if (io == 'i') temp = input_head;
    else temp = output_head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
