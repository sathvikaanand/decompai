```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include <sys/stat.h>

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    /* Exit the program, simulating a non-returning subroutine */
    exit(1);
}

int verify_username(char *username) {
    puts("Verifying username...");
    if (strstr(username, "%n") == NULL && strchr(username, ' ') == NULL) {
        printf("Verified username: ");
        for (size_t i = 0; i < strlen(username); i++) {
            username[i] = tolower(username[i]);
        }
        printf("%s\n", username);
        return 0;
    } else {
        puts("Illegal character sequence in username!");
        return 1;
    }
}

int main(void) {
    char username[256];
    char filename[32769];
    struct stat file_stat;

    if (signal(SIGALRM, (void (*)(int)) timeout_handler) != SIG_ERR) {
        alarm(60);
    }

    printf("Your ticket is %p... Please provide your name: ", &file_stat);
    fflush(stdout);

    if (fgets(username, sizeof(username), stdin) == NULL) {
        perror("fgets");
        return 1;
    }

    size_t len = strlen(username);
    if (username[len - 1] == '\n') {
        username[len - 1] = '\0';
    }

    if (verify_username(username) == 0) {
        fflush(stdout);
        printf("\nPlease provide the name of the file to be analyzed: ");
        fflush(stdout);

        if (fgets(filename, sizeof(filename), stdin) == NULL) {
            perror("fgets");
            return 1;
        }

        len = strlen(filename);
        if (filename[len - 1] == '\n') {
            filename[len - 1] = '\0';
        }

        if (strlen(filename) < sizeof(filename)) {
            if (stat(filename, &file_stat) == 0) {
                puts(filename);
                printf("\tDevice: %d\n", file_stat.st_dev);
                printf("\tI-node: %d\n", file_stat.st_ino);
                printf("\tMode  : %x\n", file_stat.st_mode);
                printf("\tUID   : %d\n", file_stat.st_uid);
                printf("\tGID   : %d\n", file_stat.st_gid);
                printf("\tSize  : %lld\n", file_stat.st_size);
                return 0;
            } else {
                puts("Access denied!");
            }
        } else {
            puts("File name too long!");
        }
    } else {
        puts("Username not verified!");
    }

    return 1;
}
```