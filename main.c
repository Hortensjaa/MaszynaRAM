#include "main_service.c"

int main(void) {
    for (int i = 1; i < MEMORY_SIZE; i++) memo[i] = INT_MIN;

    // wczytywanie tasmy wejsciowej
    int n;
    printf("Podaj, ile liczb pojawi sie na tasmie wejsciowej:\n");
    scanf("%d", &n);
    int input;
    printf("Wprowadz zawartosc tasmy wejsciowej (liczby calkowite rodzielone spacjami):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        insert_input_tape(input);
    }

    printf("Wpisz 0, aby wybrac tryb krokowy lub 1, aby wybrac tryb ciagly dzialania programu\n");
    int choose = 2;
    while (choose != 0 && choose != 1) {
        scanf("%d", &choose);
        if (choose == 0) live_mode = true;
        else if (choose == 1) live_mode = false;
        else printf("Wybierz 0 lub 1\n");
    }

    //tryb krokowy
    if (live_mode == true) {
        printf("Wprowadzaj kolejno instrukcje\n");
        char command[MAX_TAG_LEN];
        while (true) {
            print_status();
            scanf("%s", command);
            without_tag_service(command);
        }
    }

    // tryb ciagly
    else {
        printf("Wpisz 0, jezeli chcesz wybrac plik wejsciowy lub 1, aby wpisywac instrukcje do terminala\n");
        scanf("%d", &choose);
        if (choose == 0) { // TODO: obsluga pliku wejsciowego
            printf("Wybierz plik wejsciowy: ");
        }
        else if (choose == 1) {
            printf("Wpisuj kolejne instrukcje; gdy skonczysz, wpisz 'end'\n"); // TODO: legalnosc etykiet, zeby nie mozna bylo wpisac '<>'
            stream_disabled = true;
            strcpy(tag_on_stack, "<illegal tag>");
            char command[MAX_TAG_LEN];
            while (true){
                scanf("%s", command);
                if (equal_string(command, "end")) break;
                without_tag_service(command);
            }
            stream_disabled = false;
            run_command_queue(TAG_PLACEHOLDER);
        }
    }
}
