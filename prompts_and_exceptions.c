#include "prompts_and_exceptions.h"

// BŁĘDY, WYJĄTKI I INNE KOMUNIKATY

// BŁĘDY I WYJĄTKI
int invalid_mem_index() {
    printf("Niepoprawny numer komorki\n");
    return INT_MIN;
}

int invalid_argument() {
    printf("Niepoprawny argument\n");
    return INT_MIN;
}

void invalid_command() {
    printf("Niepoprawna komenda. Wybierz ktoras z ponizszych:\n"
           "LOAD, STORE, ADD, SUB, MULT, DIV, READ, WRITE, JUMP, JGTZ, JZERO, HALT\n");
}

bool empty_accumulator() {
    printf("Akumulator jest pusty\n");
    return false;
}

bool empty_input() {
    printf("Tasma wejsciowa jest pusta - podaj inna komende\n");
    return false;
}

// INNE KOMUNIKATY
void index_redirect_prompt(int index, int redirect) {
    printf("Proba wykonania dzialania na liczbie %d znajdujacej sie w komorce nr %d "
           "(przekierowane z komorki nr %d)\n", memo[index], index, redirect);
}

void index_prompt(int index) {
    printf("Proba wykonania dzialania na liczbie %d znajdujacej sie w komorce nr %d\n", memo[index], index);
}

void number_prompt(int a) {
    printf("Proba wykonania dzialania na liczbie %d\n", a);
}

void memory_index_redirect_prompt(int index) {
    printf("Proba wykonania dzialania w komorce nr %d (przekierowanie z komorki nr %d)\n", memo[index], index);
}

void memory_index_prompt(int index) {
    printf("Proba wykonania dzialania w komorce nr %d\n", index);
}

void stream_disable_prompt(char tag[]) {
    printf("Warunek skoku spelniony; blokujemy strumien, dopoki nie napotkamy etykiety %s\n", tag);
}

void jump_to_tag_prompt(char tag[]) {
    printf("Warunek skoku spelniony; przechodzimy do etykiety %s\n", tag);
}

void condition_false_prompt() {
    printf("Warunek skoku nie jest spelniony\n");
}
