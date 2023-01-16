#include "main_service.c"

int main(void) {
    for (int i = 1; i < MEMORY_SIZE; i++) memo[i] = INT_MIN;
    get_input_tape();
// TODO: obsluga trybu ciaglego (jako zablokowanego, a pozniej puszczenia kolejki?)
//    printf("Wpisz 0, aby wybrać tryb krokowy lub 1, aby wybrać tryb ciągły działania programu\n");
//    int n;
//    scanf("%d", &n);
//    if (n == 0) live_mode = true;
//    else if (n == 1) live_mode = false;
//    else printf("Wybierz 0 lub 1\n");

    printf("Wprowadzaj kolejno instrukcje\n");
    char command[MAX_TAG_LEN];

    //petla glowna TODO: nie działa dla przykladu z sumą dla liczb wiekszych od 3 (?!)
    while (true) {
        print_status();
        scanf("%s", command);
        without_tag_service(command);
    }
}
