#include "main_service.h"

bool live_mode = true;

// KOMENDY MASZYNY RAM

// obsluga pamieci

void read(int n, ...) {
    // TODO: powtarzajace sie linijki kodu - da się to wrzucic do jednej funkcji? Chociaż obsługę tagów...
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (stream_disabled == false) {
        bool b = read_index(arg);
        if (b) insert_command_node("READ", arg, tag);
    }
    else insert_command_node("READ", arg, tag);
}

void store(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (stream_disabled == false) {
        bool b = store_index(arg);
        if (b) insert_command_node("STORE", arg, tag);
    }
    else insert_command_node("STORE", arg, tag);
}

// obsluga akumulatora

void load(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (stream_disabled == false) {
        bool b = load_value(arg);
        if (b) insert_command_node("LOAD", arg, tag);
    }
    else insert_command_node("LOAD", arg, tag);
}

void add(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (stream_disabled == false) {
        bool b = add_value(arg);
        if (b) insert_command_node("ADD", arg, tag);
    }
    else insert_command_node("ADD", arg, tag);
}

void sub(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (stream_disabled == false) {
        bool b = sub_value(arg);
        if (b) insert_command_node("SUB", arg, tag);
    }
    else insert_command_node("SUB", arg, tag);
}

void mult(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (stream_disabled == false) {
        bool b = mult_value(arg);
        if (b) insert_command_node("MULT", arg, tag);
    }
    else insert_command_node("MULT", arg, tag);
}

void diiv(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (stream_disabled == false) {
        bool b = div_value(arg);
        if (b) insert_command_node("DIV", arg, tag);
    }
    else insert_command_node("DIV", arg, tag);
}

void write(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    if (stream_disabled == false) {
        bool b = write_value(arg);
        if (b) insert_command_node("WRITE", arg, tag);
    }
    else insert_command_node("WRITE", arg, tag);
}

// przekierowania

void jump(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    insert_command_node("JUMP", arg, tag);
    if (stream_disabled == false) jump_tag(tag);
}

void jzero(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    insert_command_node("JZERO", arg, tag);
    if (stream_disabled == false)jzero_tag(tag);
}

void jgtz(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    char arg[MAX_ARG_LEN];
    scanf("%s", arg);
    insert_command_node("JGTZ", arg, tag);
    if (stream_disabled == false) jgtz_tag(tag);
}

void halt(int n, ...) {
    char tag[MAX_TAG_LEN];
    if (n == 0) strcpy(tag, TAG_PLACEHOLDER);
    if (n == 1) {
        va_list ptr;
        va_start(ptr, n);
        strcpy(tag, va_arg(ptr, char*));
        va_end(ptr);
        if (stream_disabled == true && equal_string(tag, tag_on_stack)) stream_disabled = false;
    }
    if (stream_disabled == false) halt_tag();
}

// OGOLNA OBSLUGA

void print_status() {
    printf("%s", PRINT_LINE);
    printf("Kolejka instrukcji: "); print_command_queue();
    printf("Tasma wejsciowa: "); print_tape('i');
    if (acc != INT_MIN) printf("Akumulator: %d\n", acc);
    else printf("Akumulator: \n");
    printf("Zajete komorki pamieci:\n"); print_memory();
    printf("Tasma wyjsciowa: "); print_tape('o');
    printf("%s", PRINT_LINE);
}