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

bool load_value(char arg[]) {
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    acc = a;
    printf("Wczytano liczbe %d do akumulatora\n", a);
    return true;
}

bool add_value(char arg[]) {
    if (acc == INT_MIN) return empty_accumulator();
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    acc += a;
    printf("Dodano liczbe %d do wartosci akumulatora\n", a);
    return true;
}

bool sub_value(char arg[]) {
    if (acc == INT_MIN) return empty_accumulator();
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    acc -= a;
    printf("Odjeto liczbe %d od wartosci akumulatora\n", a);
    return true;
}

bool mult_value(char arg[]) {
    if (acc == INT_MIN) return empty_accumulator();
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    acc *= a;
    printf("Wartosc akumulatora pomnozono przez %d\n", a);
    return true;
}

bool div_value(char arg[]) {
    if (acc == INT_MIN) return empty_accumulator();
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    acc /= a;
    printf("Wartosc akumulatora podzielono przez %d\n", a);
    return true;
}

bool write_value(char arg[]) {
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    insert_output_tape(a);
    printf("Wypisano %d na tasme wyjsciowa\n", a);
    return true;
}