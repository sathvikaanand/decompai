```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

void timeout_handler() {
    puts("\n\nTimeout expired!");
    _exit(1);
}

int main() {
    int ret;
    char *input;
    size_t len;
    struct stat file_stat;
    char filename[1024];
    char cat_command[1024];
    long local_stack_guard = 0xdeadbeef;
    uid_t user_id;
    
    signal(SIGALRM, timeout_handler);
    alarm(10);  // Set alarm for 10 seconds
    user_id = getuid();

    printf("Please provide the file to access: ");
    fflush(stdout);
    input = fgets(filename, sizeof(filename), stdin);
    
    if (input == NULL) {
        perror("fgets");
        exit(1);
    }

    // Remove newline character
    len = strlen(filename);
    if (filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    // Get file stats
    ret = stat(filename, &file_stat);
    if (ret != 0) {
        perror("stat");
        exit(1);
    }

    // Check file ownership
    if (file_stat.st_uid == user_id) {
        snprintf(cat_command, sizeof(cat_command), "/bin/cat %s", filename);
        system(cat_command);
    } else {
        printf("You do not own this file! The owner has id %d while yours is %d. Action aborted...\n", file_stat.st_uid, user_id);
    }

    return 0;
}
```