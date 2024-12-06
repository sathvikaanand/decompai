```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int verify_username(char *username) {
    char *illegal_char;

    puts("Verifying username...");
    illegal_char = strstr(username, "%n");
    if (illegal_char == NULL) {
        illegal_char = strchr(username, ' ');
    }

    if (illegal_char == NULL) {
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
    char username[32769];
    char filename[255];
    struct stat file_info;

    if (signal(SIGALRM, timeout_handler) != SIG_ERR) {
        alarm(60); // Set an alarm for 60 seconds
    }

    printf("Your ticket is %p... Please provide your name: ", &file_info);
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
            if (stat(filename, &file_info) == 0) {
                puts(filename);
                printf("\tDevice: %d\n", file_info.st_dev);
                printf("\tI-node: %d\n", file_info.st_ino);
                printf("\tMode  : %x\n", file_info.st_mode);
                printf("\tUID   : %d\n", file_info.st_uid);
                printf("\tGID   : %d\n", file_info.st_gid);
                printf("\tSize  : %d\n", (int)file_info.st_size);
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