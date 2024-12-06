```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int timeout = 0;
int debug = 0;
int i = 0;
int checksum = 0;
char c;

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int main(int argc, char *argv[]) {
    char *workdir = NULL;
    char data[4096];
    int j = 0;
    
    // Parse command line arguments
    int opt;
    while ((opt = getopt(argc, argv, "t:w:d")) != -1) {
        switch (opt) {
            case 't':
                timeout = atoi(optarg);
                break;
            case 'w':
                workdir = strdup(optarg);
                break;
            case 'd':
                debug = 1;
                break;
            default:
                fprintf(stderr, "Usage: %s -t <timeout> -w <workdir> [-d]\n", argv[0]);
                exit(1);
        }
    }

    // Setup timeout alarm
    if (timeout != 0) {
        signal(SIGALRM, timeout_handler);
        alarm(timeout);
    }

    // Change working directory if specified
    if (workdir != NULL) {
        chdir(workdir);
    }

    // Print working directory
    getcwd(data, sizeof(data));
    if (debug) {
        printf("Running service in %s as user %d...\n", data, getuid());
    }

    printf("Welcome to the checksum verifier service!\nYour service ticket id is: %p\nPlease provide the data to verify: ", main);
    fflush(stdout);

    // Read data from stdin
    i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        data[i++] = c;
        data[i] = '\0';
    }

    // Calculate checksum
    printf("Received a buffer of length %d\n", i);
    fflush(stdout);

    checksum = 0;
    if (i > 0) {
        for (int j = 0; j < i; j++) {
            checksum ^= data[j];
        }
    }

    // Check checksum
    if (checksum != 0) {
        puts("Checksum failed! Exiting now...");
        fflush(stdout);
        exit(1);
    }

    puts("Checksum is correct!");
    fflush(stdout);

    return 0;
}
```