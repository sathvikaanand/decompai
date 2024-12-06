```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int _timeout = 0;
int _debug = 0;
int _checksum = 0;
int _i = 0;
char _c;
int _j;

void _timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int main(int argc, char *argv[]) {
    char work_dir[4096] = {0};
    char buffer[1024] = {0};
    int opt;
    char* workdir = NULL;

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
                fprintf(stderr, "Usage: %s -t <timeout> -w <workdir> [-d]\n", argv[0]);
                exit(1);
        }
    }

    if (_timeout > 0) {
        signal(SIGALRM, _timeout_handler);
        alarm(_timeout);
    }

    if (workdir) {
        chdir(workdir);
        free(workdir);
    }

    getcwd(work_dir, sizeof(work_dir));

    if (_debug) {
        printf("Running service in %s as user %d...\n", work_dir, getuid());
    }

    printf("Welcome to the checksum verifier service!\nYour service ticket id is: %p\nPlease provide the data to verify: ", main);
    fflush(stdout);

    _i = 0;
    while ((_c = getchar()) != '\n' && _c != EOF) {
        buffer[_i++] = _c;
    }
    buffer[_i] = '\0';

    printf("Received a buffer of length %d\n", _i);
    fflush(stdout);

    _checksum = 0;

    for (int j = 0; j < _i; ++j) {
        _checksum ^= buffer[j];
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