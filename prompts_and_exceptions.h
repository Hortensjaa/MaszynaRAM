#ifndef MASZYNARAM_PROMPTS_AND_EXCEPTIONS_H
#define MASZYNARAM_PROMPTS_AND_EXCEPTIONS_H

#include "support_functions_and_declarations.h"

// KOMUNIKATY O BLEDACH I WYJATKACH

int invalid_mem_index(); // komunikat o niepoprawnym indeksie komorki
int invalid_argument(); // komunikat o niepoprawnym argumencie
void invalid_command(); // komunikat o niepoprawnej komendzie
bool empty_accumulator(); // komunikat o pustym akumulatorze
bool empty_input(); // komunikat o pustym wejsciu

void index_redirect_prompt(int index, int redirect); // ^n
void index_prompt(int index); // n
void number_prompt(int a); // =n

void memory_index_redirect_prompt(int index); // ^i
void memory_index_prompt(int index); // i

void stream_disable_prompt(char tag[]); // warunek zostal spelniony, wiec blokujemy strumien az napotkamy etykiete
void jump_to_tag_prompt(char tag[]); // warunek jest spelniony, wiec idziemy do etykiety
void condition_false_prompt(); // warunek nie jest spelniony, wiec ignorujemy

#endif //MASZYNARAM_PROMPTS_AND_EXCEPTIONS_H
