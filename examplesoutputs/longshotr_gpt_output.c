```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>

void timeout_exit() {
    printf("\n\nTimeout expired!\n");
    exit(1);
}

int verify_username(char *username) {
    int i;
    char *illegal_char;

    printf("Verifying username...\n");
    illegal_char = strstr(username, "%n");
    if (illegal_char == NULL) {
        illegal_char = strstr(username, " ");
    }
    
    if (illegal_char == NULL) {
        printf("Verified username: ");
        for (i = 0; username[i] != '\0'; i++) {
            username[i] = tolower(username[i]);
        }
        printf("%s\n", username);
        return 0;
    } else {
        printf("Illegal character sequence in username!\n");
        return 1;
    }
}

int entry() {
    char username[256];
    char filename[65536];
    struct stat file_stat;
    int status;

    signal(SIGALRM, timeout_exit);
    alarm(10); // Assuming 10 seconds timeout

    printf("Your ticket is %p... Please provide your name: ", (void *)entry);
    fflush(stdout);
    
    if (fgets(username, sizeof(username), stdin) == NULL) {
        perror("fgets");
        return 1;
    }
    
    if (username[strlen(username) - 1] == '\n') {
        username[strlen(username) - 1] = '\0'; // Remove newline
    }

    if (verify_username(username) == 0) {
        printf("\nPlease provide the name of the file to be analyzed: ");
        fflush(stdout);
        
        if (fgets(filename, sizeof(filename), stdin) == NULL) {
            perror("fgets");
            return 1;
        }
        
        if (filename[strlen(filename) - 1] == '\n') {
            filename[strlen(filename) - 1] = '\0'; // Remove newline
        }

        if (strlen(filename) > 256) {
            printf("File name too long!\n");
            return 1;
        }

        status = stat(filename, &file_stat);
        if (status == 0) {
            printf("File information:\n");
            printf("\tDevice: %ld\n", file_stat.st_dev);
            printf("\tI-node: %ld\n", file_stat.st_ino);
            printf("\tMode  : %o\n", file_stat.st_mode);
            printf("\tUID   : %d\n", file_stat.st_uid);
            printf("\tGID   : %d\n", file_stat.st_gid);
            printf("\tSize  : %ld\n", file_stat.st_size);
        } else {
            printf("Access denied!\n");
            return 1;
        }
    } else {
        printf("Username not verified!\n");
        return 1;
    }
    return 0;
}

int main() {
    return entry();
}
```