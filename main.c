#include "main_service.c"

int main(void) {
    for (int i = 1; i < MEMORY_SIZE; i++) memo[i] = INT_MIN;
    get_input_tape();
//
//    printf("Wpisz 0, aby wybrać tryb krokowy lub 1, aby wybrać tryb ciągły działania programu\n");
//    int n;
//    scanf("%d", &n);
//    if (n == 0) live_mode = true;
//    else if (n == 1) live_mode = false;
//    else printf("Wybierz 0 lub 1\n");

    printf("Wprowadzaj kolejno instrukcje\n"); // TODO: W tym trybie da się tylko odwoływać do wcześniej zadeklarowanych etykiet
    char command[20];

    //petla glowna
    while (true) {
        print_status();
        scanf("%s", command);
        if (equal_string(command, "HALT")) halt(0);
        else if (equal_string(command, "READ")) read(0);
        else if (equal_string(command, "STORE")) store(0);
        else if (equal_string(command, "LOAD")) load(0);
        else if (equal_string(command, "WRITE")) write(0);
        else if (equal_string(command, "ADD")) add(0);
        else if (equal_string(command, "SUB")) sub(0);
        else if (equal_string(command, "MULT")) mult(0);
        else if (equal_string(command, "DIV")) diiv(0);
        else if (equal_string(command, "JUMP")) jump(0);
        else if (equal_string(command, "JZERO")) jzero(0);
        else if (equal_string(command, "JGTZ")) jgtz(0);
        else {
            char tag[MAX_TAG_LEN];
            strcpy(tag, command);
            scanf("%s", command);
            if (equal_string(command, "HALT")) halt(1, tag);
            if (equal_string(command, "READ")) read(1, tag);
            else if (equal_string(command, "STORE")) store(1, tag);
            else if (equal_string(command, "LOAD")) load(1, tag);
            else if (equal_string(command, "WRITE")) write(1, tag);
            else if (equal_string(command, "ADD")) add(1, tag);
            else if (equal_string(command, "SUB")) sub(1, tag);
            else if (equal_string(command, "MULT")) mult(1, tag);
            else if (equal_string(command, "DIV")) diiv(1, tag);
            else if (equal_string(command, "JUMP")) jump(1, tag);
            else if (equal_string(command, "JZERO")) jzero(1, tag);
            else if (equal_string(command, "JGTZ")) jgtz(1, tag);
            else invalid_command();
        }
    }
}
