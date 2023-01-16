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

    //petla glowna
    while (true) {
        print_status();
        scanf("%s", command);
        // TODO: to juz chyba latwo bedzie ujednolicić, nie? :>
        if (equal_string(command, "LOAD")) without_tag_service (0);
        else if (equal_string(command, "ADD")) without_tag_service (1);
        else if (equal_string(command, "SUB")) without_tag_service (2);
        else if (equal_string(command, "MULT")) without_tag_service (3);
        else if (equal_string(command, "DIV")) without_tag_service (4);
        else if (equal_string(command, "WRITE")) without_tag_service (5);
        else if (equal_string(command, "STORE")) without_tag_service (6);
        else if (equal_string(command, "READ")) without_tag_service (7);
        else if (equal_string(command, "JUMP")) without_tag_service (8);
        else if (equal_string(command, "JZERO")) without_tag_service (9);
        else if (equal_string(command, "JGTZ")) without_tag_service (10);
        else if (equal_string(command, "HALT")) without_tag_service (11);
//        else if (equal_string(command, "HALT")) halt(0);
        else {
            char tag[MAX_TAG_LEN];
            strcpy(tag, command);
            scanf("%s", command);
            if (equal_string(command, "LOAD")) with_tag_service (tag, 0);
            else if (equal_string(command, "ADD")) with_tag_service (tag, 1);
            else if (equal_string(command, "SUB")) with_tag_service (tag, 2);
            else if (equal_string(command, "MULT")) with_tag_service (tag, 3);
            else if (equal_string(command, "DIV")) with_tag_service (tag, 4);
            else if (equal_string(command, "WRITE")) with_tag_service (tag, 5);
            else if (equal_string(command, "STORE")) with_tag_service (tag, 6);
            else if (equal_string(command, "READ")) with_tag_service (tag, 7);
            else if (equal_string(command, "JUMP")) with_tag_service (tag, 8);
            else if (equal_string(command, "JZERO")) with_tag_service (tag, 9);
            else if (equal_string(command, "JGTZ")) with_tag_service (tag, 10);
            else if (equal_string(command, "HALT")) with_tag_service (tag, 11);
//            else if (equal_string(command, "HALT")) halt(1, tag);
            else invalid_command();
        }
    }
}
