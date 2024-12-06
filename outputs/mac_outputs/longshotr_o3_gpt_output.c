```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#define TIMEOUT 60

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int verify_username(char *username) {
    puts("Verifying username...");
    if (strstr(username, "%n") == NULL && strchr(username, ' ') == NULL) {
        printf("Verified username: ");
        for (size_t i = 0; i < strlen(username); i++) {
            username[i] = (char)tolower((unsigned char)username[i]);
        }
        printf("%s\n", username);
        return 0;
    }
    puts("Illegal character sequence in username!");
    return 1;
}

int main(void) {
    struct stat file_stat;
    char username[256];
    char filename[32769];
    char buffer[255];

    if (TIMEOUT != 0) {
        signal(SIGALRM, (void (*)(int))timeout_handler);
        alarm(TIMEOUT);
    }

    printf("Your ticket is %p... Please provide your name: ", &username);
    fflush(stdout);

    if (fgets(username, sizeof(username), stdin) == NULL) {
        perror("fgets");
        exit(1);
    }
    username[strcspn(username, "\n")] = 0;

    if (verify_username(username) == 0) {
        fflush(stdout);
        printf("\nPlease provide the name of the file to be analyzed: ");
        fflush(stdout);
        if (fgets(filename, sizeof(filename), stdin) == NULL) {
            perror("fgets");
            exit(1);
        }
        filename[strcspn(filename, "\n")] = 0;

        if (strlen(filename) < 32768) {
            strcpy(buffer, filename);
            if (stat(buffer, &file_stat) == 0) {
                printf("%s\n", buffer);
                printf("\tDevice: %d\n", file_stat.st_dev);
                printf("\tI-node: %d\n", file_stat.st_ino);
                printf("\tMode  : %o\n", file_stat.st_mode);
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