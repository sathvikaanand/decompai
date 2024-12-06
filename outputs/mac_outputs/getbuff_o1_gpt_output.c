```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <pwd.h>

volatile int _timeout = 0; 
volatile int _debug = 0;
volatile int _i = 0;
volatile int _j = 0;
volatile int _checksum = 0;
volatile char _c = 0;

void _timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

void usage(const char *program_name) {
    fprintf(stderr, "Usage: %s -t <timeout> -w <workdir> [-d]\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    int opt;
    char *workdir = NULL;
    char buffer[1024] = {0};
    char cwd[4096];
    
    while ((opt = getopt(argc, argv, "t:w:d")) != -1) {
        switch (opt) {
            case 't':
                _timeout = atoi(optarg);
                break;
            case 'w':
                workdir = strdup(optarg);
                break;
            case 'd':
                _debug = 1;
                break;
            default:
                usage(argv[0]);
        }
    }

    if (_timeout != 0) {
        signal(SIGALRM, _timeout_handler);
        alarm(_timeout);
    }
    if (workdir != NULL) {
        chdir(workdir);
    }
    
    getcwd(cwd, sizeof(cwd));
    if (_debug) {
        printf("Running service in directory %s as user %d...\n", cwd, getuid());
    }

    printf("Welcome to the checksum verifier service!\n    Your service ticket id is: %p\n    Please provide the data to verify: ", (void *)main);
    fflush(stdout);

    _i = 0;
    while ((_c = getchar()) != '\n' && _c != EOF) {
        buffer[_i++] = _c;
    }
    buffer[_i] = '\0';

    printf("Received a buffer of length %d\n", _i);
    fflush(stdout);

    _checksum = 0;
    for (int idx = 0; idx < _i; idx++) {
        _checksum ^= buffer[idx];
    }

    if (_checksum != 0) {
        puts("Checksum failed! Exiting now...");
        fflush(stdout);
        exit(1);
    }

    puts("Checksum is correct!");
    fflush(stdout);

    return 0;
}
```