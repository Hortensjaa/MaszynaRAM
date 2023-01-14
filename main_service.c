#include "main_service.h"

// KOMENDY MASZYNY RAM

// obsluga pamieci

void read() {
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    read_index(arg);
}

void store() {
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    store_index(arg);
}

// obsluga akumulatora

void load() {
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    load_value(arg);
}

void add() {
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (acc == INT_MIN) return empty_accumulator();
    add_value(arg);
}

void sub() {
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (acc == INT_MIN) return empty_accumulator();
    sub_value(arg);
}

void mult() {
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (acc == INT_MIN) return empty_accumulator();
    mult_value(arg);
}

void diiv() {
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (acc == INT_MIN) return empty_accumulator();
    div_value(arg);
}

void write() {
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    write_value(arg);
}

// przekierowania

void jump() {}
bool jzero() {return false;}
bool jgtz() {return false;}

void halt() {
    exit(0);
}

// WYPISYWANIE STANU

void print_status() {
    printf("%s", PRINT_LINE);
    printf("Tasma wejsciowa: "); print_tape('i');
    if (acc != INT_MIN) printf("Akumulator: %d\n", acc);
    else printf("Akumulator: \n");
    printf("Zajete komorki pamieci:\n"); print_memory();
    printf("Tasma wyjsciowa: "); print_tape('o');
    printf("%s", PRINT_LINE);
}