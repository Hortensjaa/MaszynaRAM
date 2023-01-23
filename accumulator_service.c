#include "accumulator_service.h"

// OBSLUGA AKUMULATORA - DZIAŁANIA NA AKUMULATORZE (MATEMATYCZNE ORAZ LOAD), WYPISANIE Z AKUMULATORA NA WYJSCIE (WRITE)

/* wartość akumulatora początkowo ustawiana jest na INT_MIN; jest to w pewnym sensie placeholder
 reprezentujący pusty akumulator */
int acc = INT_MIN;

// funkcja pomocnicza obsługująca wczytywanie argumentów - wartości
int acc_arg_service(char arg[]) {
    // argumenty funkcji matematycznych oraz WRITE mogą mieć trzy postaci:

    // wczytywanie wartości z komórki o numerze przechowywanym w komórce o numerze będącym argumentem
    if (arg[0] == '^') {
        arg = arg + 1; // przesuwamy wskaźnik za '^'
        int index_index = atoi(arg); // resztę argumentu traktujemy jako inta
        // wyjątki: ujemny nr komórki, nr komórki przekraczający wielkosc pamięci, pusta komórka pod indeksem
        if (index_index <= 0 || index_index >= MEMORY_SIZE || memo[index_index] == INT_MIN) return invalid_mem_index();
        // pobieramy wartość z komórki o wczytanym indeksie
        int index = memo[index_index];
        // wyjątki: ujemny indeks, indeks przekraczajacy rozmiar pamieci, pusta komorka pod indeksem
        if (index <= 0 || index >= MEMORY_SIZE || memo[index] == INT_MIN) return invalid_mem_index();
        // wypisanie komunikatu o poprawnym wczytaniu argumentu i probie wykonania operacji
        index_redirect_prompt(index, index_index);
        // zwracamy wartosc, na ktorej bedziemy
        return memo[index];
    }

    // wczytywanie wartości z komórki o numerze będącym argumentem
    else if ('1' <= arg[0] && arg[0] <= '9') {
        int index = atoi(arg);
        if (index <= 0 || index >= MEMORY_SIZE|| memo[index] == INT_MIN) return invalid_mem_index();
        index_prompt(index);
        return memo[index];
    }

    // wczytywanie "samej" wartości podanej jako argument
    else if (arg[0] == '=') {
        arg = arg + 1;
        int a = atoi(arg);
        number_prompt(a);
        return a;
    }
    // jeżeli nie weszliśmy do żadnego przypadku, to znaczy, że argument nie był poprawny
    return invalid_argument();
}

// OPERACJE MASZYNY RAM

// LOAD
bool load_value(char arg[]) {
    int a = acc_arg_service(arg); // wczytanie argumentu
    if (a == INT_MIN) return false;
    acc = a; // zamiana wartości akumulatora na wczytany argument
    printf("Wczytano liczbe %d do akumulatora\n", a); // informacja, ze operacja została wykonana
    return true; // zwrócenie wartości true - operacja się udała
}
// kolejne operacje zachodzą niemal analogicznie:
// ADD
bool add_value(char arg[]) {
    // w przypadku operacji arytmetycznych, musimy jeszcze sprawdzić, czy akumulator nie jest pusty
    if (acc == INT_MIN) return empty_accumulator();
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    acc += a;
    printf("Dodano liczbe %d do wartosci akumulatora\n", a);
    return true;
}

// SUB
bool sub_value(char arg[]) {
    if (acc == INT_MIN) return empty_accumulator();
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    acc -= a;
    printf("Odjeto liczbe %d od wartosci akumulatora\n", a);
    return true;
}

// MULT
bool mult_value(char arg[]) {
    if (acc == INT_MIN) return empty_accumulator();
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    acc *= a;
    printf("Wartosc akumulatora pomnozono przez %d\n", a);
    return true;
}

// DIV
bool div_value(char arg[]) {
    if (acc == INT_MIN) return empty_accumulator();
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    acc /= a;
    printf("Wartosc akumulatora podzielono przez %d\n", a);
    return true;
}

// WRITE
bool write_value(char arg[]) {
    int a = acc_arg_service(arg);
    if (a == INT_MIN) return false;
    insert_tape(a, &output_head); // wypisujemy argument na taśmę wyjściową
    printf("Wypisano %d na tasme wyjsciowa\n", a);
    return true;
}