```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t timeout = 0;

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    _exit(1);
}

int get_int(void) {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    return strtol(buffer, NULL, 0);
}

char get_char(void) {
    char buffer[16];
    fgets(buffer, sizeof(buffer), stdin);
    return buffer[0];
}

int main(void) {
    int table[1024] = {0};
    char buffer[1024];

    if (timeout) {
        signal(SIGALRM, timeout_handler);
        alarm(timeout);
    }

    puts("This service allows you to store integers in a table for future use.");
    puts("Commands: Store (s), Read (r), Dump (d), Quit (q)");

    while (1) {
        printf("Command: ");
        fflush(stdout);
        fgets(buffer, sizeof(buffer), stdin);
        
        switch (buffer[0]) {
            case 'd':
                for (int i = 0; i < 1024; i++) {
                    printf("%04d: %08d (0x%08x)\n", i, table[i], table[i]);
                }
                break;
            
            case 'q':
                puts("Quitting...");
                return 0;

            case 'r':
                printf("Index: ");
                fflush(stdout);
                int index = get_int();
                printf("Value: %08d (0x%08x)\n", table[index], table[index]);
                break;

            case 's':
                printf("Index: ");
                fflush(stdout);
                index = get_int();
                printf("Value: ");
                fflush(stdout);
                int value = get_int();
                printf("Updating table value at index %04d with %08d (0x%08x): previous value was %08d (0x%08x)\n", index, value, value, table[index], table[index]);
                table[index] = value;
                break;

            default:
                if (buffer[0] != '\n') {
                    printf("Unknown command %c\n", buffer[0]);
                }
                break;
        }
    }
}
```