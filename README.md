# MaszynaRAM
Symulator maszyny RAM napisany w języku C.
Szczegółowe opisy poszczególnych funkcji znajdują się w plikach z ich definicjami. Ze względu na ilość plików, poniżej krótki przewodnik:

## support_functions(_and_declarations).c /.h
Deklaracje najważniejszych zmiennych globalnych (akumulator, komórki pamięci itd.) i funkcje pomocnicze.

## input_output_tapes.c /.h
Obsługa taśm wejściowej i wyjściowej. Zaimplementowane są one jako listy jednokierunkowe, których głowy zapamiętujemy globalnie.

## accumulator_service.c /.h
Obsługa operacji, które przyjmują argumenty będące wartościami tzn. operacje na akumulatorze (LOAD i operacje arytmetyczne) oraz WRITE, wraz z obsługą argumentów dla nich.

## memory_service.c /.h
Obsługa operacji, które za argumenty przyjmują numery komórek pamięci - STORE i READ - wraz z obsługą tych argumentów.

## commands_queue.c /.h
Obsługa kolejki komend; kolejka komend pozwala na wykonywanie skoków.

## stream_control.c /.h
Obsługa strumienia instrukcji; implementacja komend skoku JUMP, JZERO, JGTZ oraz HALT, które mogą blokować strumień.

## main_service.c /.h
Dwie najważniejsze funkcje sterujące całym programem, "słownik" (dwie tablice) przypisujące numerom komendy maszyny RAM oraz wypisywanie stanu maszyny.

## prompts_and_exceptions.c /.h
Funkcje wypisujące komunikaty i informacje o błędach.

## main.c - pętla główna programu
Program działa w dwóch trybach: krokowym (który po każdej operacji wypisuje aktualny stan maszyny) oraz ciągłym, który ze standardowego wejścia lub pliku tekstowego wczytuje kolejne instrukcje i egzekwuje je po wczytaniu wszystkich oraz wypisuje stan maszyny po zakończeniu działania programu. 

## examples - przykłady, na których można sprawdzić działanie programu
1. *czy_ciag_rosnie.txt* - jako pierwszy argument musi zostać podana długość ciągu, 
a na kolejnych miejscach wyrazy. Zwraca 1, jeśli ciąg jest rosnący, w przeciwnym wypadku 0.
2. *czy_ciag_z_jednym_maksimum.txt* - jako pierwszy argument musi zostać podana długość ciągu,
a na kolejnych miejscach wyrazy. Sprawdza, czy ciąg jest najpierw rosnący, a później malejący. 
Zwraca 1, jeżeli warunek jest spełniony, a w przeciwnym wypadku 0.
3. *NWD.txt* - przyjmuje dwa argumenty - liczby dodatnie - i zwraca ich NWD.
4. *reszta_z_dzielenia.txt* - przyjmuje dwa argumenty - liczby dodatnie - i zwraca resztę z dzielenia większej przez mniejszą.
5. *suma_ciagu.txt* - jako pierwszy argument musi zostać podana liczba *n* początkowych
wyrazów ciągu, które chcemy wliczyć do sumy, a na kolejnych miejscach wyrazy. 
Zwraca sumę *n* początkowych wyrazów ciągu.