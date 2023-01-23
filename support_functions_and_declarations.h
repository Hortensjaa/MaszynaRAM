#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define MEMORY_SIZE 1000 // wielkosc (ilosc komorek) pamieci
#define MAX_TAG_LEN 20  // maksymalna dlugosc etykiety
#define MAX_COMMAND_LEN 6 // maksymalna dlugosc komendy
#define COMMANDS_NUMBER 12 // ilosc roznych komend maszyny RAM
#define PRINT_LINE "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
#define PRINT_LINE_DISABLED "- - - - - - - - - STREAM - DISABLED - - - - - - - - -\n"
#define TAG_PLACEHOLDER "<placeholder>" // placeholder stosowany w obsłudze etykiet


// ZMIENNE GLOBALNE

// akumulator
extern int acc;
// tablica reprezentująca komórki w pamięci maszyny RAM
extern int memo[MEMORY_SIZE];
// zmienna "pamiętająca" czy program ma działać w trybie krokowym (true), czy ciągłym (false)
extern bool live_mode;
// zmienna "pamiętająca" czy program, działający w trybie ciągłym, ma przeczytać dane z pliku (true), czy standardowego wejścia (false)
extern bool read_from_file;
// plik, z którego mogą być odczytywane dane w trybie ciągłym
extern FILE *file;
/*
 * Zmienna pamiętająca, czy "strumień" jest zablokowany. W trybie krokowym, strumień jest zablokowany wtedy, kiedy został
 * spełniony warunek skoku do etykiety, która nie została jeszcze zdefiniowana (np. w reszta_z_dzielenia.txt - możemy wykonać skok
 * do etykiety "et1" (5 wiersz), która jest zdefiniowana dopiero w wierszu 13; jeżeli zostanie spełniony warunek skoku, nie
 * wykonają się instrukcje z wierszy 6 - 12 dzięki temu, że strumień zmieni tryb na zablokowany).
*/
extern bool stream_disabled;
/*
 * Strumień zostaje odblokowany, gdy trafimy na definicję etykiety, na którą czekaliśmy (np. w reszta_z_dzielenia.txt - w
 * wierszu 5 blokujemy strumień, oczekując na etykietę "et1" - zostaje ona zapisana w tej zmiennej).
*/
extern char tag_on_stack[MAX_TAG_LEN];

// Para tablic poniżej reprezentuje słownik, który przypisuje komendzie maszyny RAM funkcję w programie, odpowiadającą jej wykonaniu
extern bool (*fun_ptr_arr[COMMANDS_NUMBER])(char*);  // funkcje
extern char names_arr[COMMANDS_NUMBER][MAX_COMMAND_LEN];  // instrukcje

// funkcja pomocnicza sprawdzająca, czy stringi są jednakowe, ignorująca wielkość liter
bool equal_string(const char* string1, const char* string2);
// wypisywanie stanu maszyny
void print_status();

#endif // DECLARATIONS_H
