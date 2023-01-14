#include "main_service.c"

int main(void) {
    for (int i = 1; i < MEMORY_SIZE; i++) memo[i] = INT_MIN;
    get_input_tape();

    printf("Wprowadzaj kolejno instrukcje\n");
    char command[20];
    while (true) {
        print_status();
        scanf("%s", command);
        if (equal_string(command, "HALT")) halt();
        else if (equal_string(command, "READ")) read();
        else if (equal_string(command, "STORE")) store();
        else if (equal_string(command, "LOAD")) load();
        else if (equal_string(command, "WRITE")) write();
        else if (equal_string(command, "ADD")) add();
        else if (equal_string(command, "SUB")) sub();
        else if (equal_string(command, "MULT")) mult();
        else if (equal_string(command, "DIV")) diiv();
        else invalid_command();
    }
}
