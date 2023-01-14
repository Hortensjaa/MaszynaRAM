#include "support_functions_and_declarations.h"

// funkcje pomocnicze

bool equal_string(const char* string1, const char* string2) {
    int i = 0;
    while (string1[i] != '\0' || string2[i] != '\0') {
        if (tolower(string1[i]) != tolower(string2[i])) return false;
        i++;
    }
    return true;
}

int pot(int a, int b) {
    int rez;
    rez = 1;
    while (b>0) {
        if (b%2) rez = rez * a;
        b = b / 2;
        a = a * a;
    }
    return rez;
}

//int number_from_getchar() {
//    char c = getchar();
//    int num = 0;
//    int is_neg = 1;
//    if (c == '-') {
//        is_neg = -1;
//        c = getchar();
//    }
//    while (isdigit(c)) {
//        num = num * 10;
//        num = num + (c - '0');
//        c = getchar();
//    }
//    num = num * is_neg;
//    return num;
//}
