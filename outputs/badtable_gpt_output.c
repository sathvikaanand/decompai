#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_SIZE 1024

void timeout_expired() {
    printf("\n\nTimeout expired!\n");
    exit(1);
}

unsigned long read_input() {
    char input[1024];
    fgets(input, sizeof(input), stdin);
    return strtol(input, NULL, 0);
}

int read_command() {
    char input[16];
    fgets(input, sizeof(input), stdin);
    return (int)input[0];
}

int main() {
    int index;
    unsigned long value;
    unsigned long table[MAX_SIZE] = {0};
    char command;
    
    signal(SIGALRM, timeout_expired);
    printf("This service allows you to store integers in a table for future use.\n");
    printf("Commands: Store (s), Read (r), Dump (d), Quit (q)\n");

    while (1) {
        printf("Command: ");
        fflush(stdout);
        command = (char)read_command();

        if (command == 'q') {
            printf("Quitting...\n");
            break;
        } else if (command == 'r') {
            printf("Index: ");
            fflush(stdout);
            index = read_input();
            printf("Value: %08lu (0x%08lx)\n", table[index], table[index]);
        } else if (command == 's') {
            printf("Index: ");
            fflush(stdout);
            index = read_input();
            printf("Value: ");
            fflush(stdout);
            value = read_input();
            printf("Updating table value at index %04d with %08lu (0x%08lx): previous value was %08lu (0x%08lx)\n",
                   index, value, value, table[index], table[index]);
            table[index] = value;
        } else if (command == 'd') {
            for (int i = 0; i < MAX_SIZE; i++) {
                printf("%04d: %08lu (0x%08lx)\n", i, table[i], table[i]);
            }
        } else {
            printf("Unknown command %c\n", command);
        }
    }

    return 0;
}
