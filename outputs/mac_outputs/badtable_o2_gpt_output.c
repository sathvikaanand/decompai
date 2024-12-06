```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define TABLE_SIZE 1024

int table[TABLE_SIZE];
unsigned int timeout = 0;

void timeout_handler() {
    puts("\n\nTimeout expired!");
    exit(1);
}

int get_int() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    return strtol(buffer, NULL, 0);
}

char get_char() {
    char buffer[16];
    fgets(buffer, sizeof(buffer), stdin);
    return buffer[0];
}

void store_value() {
    printf("Index: ");
    fflush(stdout);
    int index = get_int();

    printf("Value: ");
    fflush(stdout);
    int value = get_int();

    if (index >= 0 && index < TABLE_SIZE) {
        printf("Updating table value at index %04d with %08d (0x%08x)\n", index, value, value);
        table[index] = value;
    } else {
        printf("Index out of range.\n");
    }
}

void read_value() {
    printf("Index: ");
    fflush(stdout);
    int index = get_int();

    if (index >= 0 && index < TABLE_SIZE) {
        printf("Value: %08d (0x%08x)\n", table[index], table[index]);
    } else {
        printf("Index out of range.\n");
    }
}

void dump_values() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%04d: %08d (0x%08x)\n", i, table[i], table[i]);
    }
}

void entry() {
    if (timeout != 0) {
        signal(SIGALRM, timeout_handler);
        alarm(timeout);
    }
    puts("This service allows you to store integers in a table for future use.");
    puts("Commands: Store (s), Read (r), Dump (d), Quit (q)");
    memset(table, 0, sizeof(table));

    while (1) {
        printf("Command: ");
        fflush(stdout);
        char cmd = get_char();

        switch (cmd) {
            case 's':
                store_value();
                break;
            case 'r':
                read_value();
                break;
            case 'd':
                dump_values();
                break;
            case 'q':
                puts("Quitting...");
                return;
            default:
                if (cmd != '\n') {
                    printf("Unknown command %c\n", cmd);
                }
                break;
        }
    }
}

int main() {
    entry();
    return 0;
}
```