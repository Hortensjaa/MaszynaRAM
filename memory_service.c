#include "memory_service.h"

// obsluga wprowadzania argumentow

int mem_arg_service(char arg[]) {
    if (arg[0] == '^') {
        arg = arg + 1;
        int index = atoi(arg);
        if (memo[index] <= 0 || index >= MEMORY_SIZE || memo[index] >= MEMORY_SIZE) return invalid_mem_index();
        memory_index_redirect_prompt(index);
        return memo[index];
    }
    else if ('1' <= arg[0] && arg[0] <= '9') {
        int index = atoi(arg);
        if (index >= MEMORY_SIZE || index <= 0) return invalid_mem_index();
        memory_index_prompt(index);
        return index;
    }
    return invalid_argument();
}

// dzialania

bool read_index(char arg[]) {
    if (input_head == NULL) return empty_input();
    int index = mem_arg_service(arg);
    if (index == INT_MIN) return false;
    tape_node* cur = delete_input_tape();
    memo[index] = cur->data;
    printf("Wpisano liczbe %d z wejscia do komorki nr %d\n", cur->data, index);
    return true;
}

bool store_index(char arg[]) {
    if (acc == INT_MIN) return empty_accumulator();
    int index = mem_arg_service(arg);
    if (index == INT_MIN) return false;
    memo[index] = acc;
    printf("Wczytano liczbe %d z akumulatora do komorki nr %d\n", acc, index);
    return true;
}

// wywolania

void print_memory() {
    for (int i = 1; i < MEMORY_SIZE; i++) {
        if (memo[i] != INT_MIN) printf("%d: %d\n", i, memo[i]);
    }
}
