```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

void handle_timeout() {
    printf("\n\nTimeout expired!\n");
    exit(1);
}

void decode_base64(char *input, long output_buffer, unsigned long max_output) {
    unsigned int bit_buffer = 0;
    unsigned int bits_collected = 0;
    unsigned long output_size = 0;
    size_t input_length = strlen(input);
    
    for (unsigned long i = 0; i < input_length; i++) {
        if (bits_collected >= max_output) break;

        char *char_index = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", input[i]);
        if (char_index != NULL) {
            bit_buffer = (bit_buffer << 6) | (char_index - "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"); // 0x3f
            bits_collected += 6;

            if (bits_collected >= 8) {
                *((char *)(output_buffer + output_size)) = (char)(bit_buffer >> (bits_collected - 8));
                output_size++;
                bits_collected -= 8;
            }
        }
    }
    *((char *)(output_buffer + output_size)) = '\0'; // Null terminate
}

void list_files() {
    DIR *dir = opendir("./files");
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }
    
    struct dirent *entry;
    printf("Files:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dir);
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    char *workdir = NULL;
    int timeout = 0;
    int enable_timeout = 0;

    int opt;
    while ((opt = getopt(argc, argv, "t:w:d")) != -1) {
        switch (opt) {
            case 't':
                timeout = atoi(optarg);
                enable_timeout = 1;
                break;
            case 'w':
                workdir = strdup(optarg);
                break;
            case 'd':
                break;
            default:
                fprintf(stderr, "Usage: %s -t <timeout> -w <workdir> [-d]\n", argv[0]);
                return 1;
        }
    }

    if (enable_timeout) {
        signal(SIGALRM, handle_timeout);
        alarm(timeout);
    }

    if (workdir) {
        chdir(workdir);
    }

    char cwd[256];
    getcwd(cwd, sizeof(cwd));
    printf("Working directory: %s\n", cwd);

    int choice;
    while (1) {
        printf("Select an option:\n");
        printf("1. List files\n");
        printf("2. Read a file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        fflush(stdout);
        
        scanf("%d", &choice);
        
        if (choice == 1) {
            list_files();
        } else if (choice == 2) {
            char filename[256];
            printf("Enter the filename: ");
            fflush(stdout);
            scanf("%s", filename);
            if (strstr(filename, "..") != NULL) {
                fprintf(stderr, "Unsafe pattern detected!\n");
                continue;
            }
            read_file(filename);
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
```