# MaszynaRAM
Symulator maszyny RAM napisany w języku C.
Szczegółowe opisy poszczególnych funkcji znajdują się w plikach z ich definicjami. Bardziej ogólnie:

## support_functions(_and_declarations).c /.h
Deklaracje najważniejszych zmiennych globalnych (akumulator, komórki pamięci itd.) i funkcje pomocnicze.

## input_output_tapes.c /.h
Obsługa taśm wejściowej i wyjściowej. Zaimplementowane są one jako listy jednokierunkowe, których głowy zapamiętujemy globalnie.

## main_service.c /.h
Dwie najważniejsze funkcje sterujące całym programem, "słownik" (dwie tablice) przypisujące numerom komendy maszyny RAM oraz wypisywanie stanu maszyny.

## main.c - pętla główna programu
Program działa w dwóch trybach: krokowym (który po każdej operacji wypisuje aktualny stan maszyny) oraz ciągłym, który ze standardowego wejścia lub pliku tekstowego wczytuje kolejne instrukcje i egzekwuje je po wczytaniu wszystkich oraz wypisuje stan maszyny po zakończeniu działania programu. 
