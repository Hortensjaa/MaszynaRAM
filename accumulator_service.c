#include "accumulator_service.h"

int acc = INT_MIN; // akumulator

// obsluga wprowadzania argumentów

int acc_arg_service(char arg[]) {
    if (arg[0] == '^') {
        arg = arg + 1;
        int index_index = atoi(arg);
        if (index_index <= 0 || index_index >= MEMORY_SIZE || memo[index_index] == INT_MIN) return invalid_mem_index();
        int index = memo[index_index];
        if (index <= 0 || memo[index] == INT_MIN || index >= MEMORY_SIZE) return invalid_mem_index();
        index_redirect_prompt(index, index_index);
        return memo[index];
    }
    else if ('1' <= arg[0] && arg[0] <= '9') {
        int index = atoi(arg);
        if (index <= 0 || memo[index] == INT_MIN || index >= MEMORY_SIZE) return invalid_mem_index();
        index_prompt(index);
        return memo[index];
    }
    else if (arg[0] == '=') {
        arg = arg + 1;
        int a = atoi(arg);
        number_prompt(a);
        return a;
    }
return invalid_argument();
}

// działania

void load_value(char arg[]) {
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return;
    acc = a;
}

void add_value(char arg[]) {
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return;
    acc += a;
}

void sub_value(char arg[]) {
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return;
    acc -= a;
}

void mult_value(char arg[]) {
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return;
    acc *= a;
}

void div_value(char arg[]) {
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return;
    acc /= a;
}

void write_value(char arg[]) {
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return;
    insert_output_tape(a);
}