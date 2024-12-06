```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int main(void) {
    int user_id, file_stat;
    struct stat file_info;
    char filename[1024];
    char command[1024];

    signal(SIGALRM, timeout_handler);
    alarm(30); // Set timeout to 30 seconds

    user_id = getuid();
    printf("Please provide the file to access: ");
    fflush(stdout);

    if (!fgets(filename, sizeof(filename), stdin)) {
        perror("fgets");
    } else {
        // Remove newline character
        size_t len = strlen(filename);
        if (len > 0 && filename[len - 1] == '\n') {
            filename[len - 1] = '\0';
        }

        if (stat(filename, &file_info) != 0) {
            perror("stat");
        } else if (file_info.st_uid == user_id) {
            snprintf(command, sizeof(command), "/bin/cat %s", filename);
            system(command);
            return 0;
        } else {
            printf("You do not own this file! The owner has id %d while yours is %d. Action aborted...\n", file_info.st_uid, user_id);
        }
    }

    return 1;
}
```