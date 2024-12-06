```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>

// Global variables for options
int _timeout = 0;
int _debug = 0;

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

void decode(char *input, char *output, size_t max_output_length) {
    static const char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    if (*input == '\0' || max_output_length == 0) {
        *output = '\0';
        return;
    }

    size_t input_length = strlen(input);
    size_t decoded_length = 0;
    uint32_t buffer = 0;
    int buffer_length = 0;
    for (size_t i = 0; i < input_length && decoded_length < max_output_length - 1; i++) {
        char *char_position = strchr(base64_chars, input[i]);
        if (char_position) {
            buffer = (buffer << 6) | (char_position - base64_chars);
            buffer_length += 6;
            if (buffer_length >= 8) {
                buffer_length -= 8;
                output[decoded_length++] = (buffer >> buffer_length) & 0xFF;
            }
        }
    }
    output[decoded_length] = '\0';
}

void list_files(void) {
    DIR *dir = opendir("./files");
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    struct dirent *entry;
    puts("Files:");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        puts(entry->d_name);
    }
    closedir(dir);
}

void print_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    int opt;
    char *workdir = NULL;

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
                exit(EXIT_FAILURE);
        }
    }

    if (_timeout > 0) {
        signal(SIGALRM, (void (*)(int))timeout_handler);
        alarm(_timeout);
    }

    if (workdir) {
        chdir(workdir);
        free(workdir);
    }

    char cwd[4096];
    getcwd(cwd, sizeof(cwd));
    if (_debug) {
        printf("Running service %s in %s as user %d...\n", argv[0], cwd, getuid());
    }

    while (1) {
        int choice = 0;
        puts("Select an option:");
        puts("1. List files");
        puts("2. Read a file");
        puts("3. Exit");
        printf("Enter your choice: ");
        fflush(stdout);

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) {
            list_files();
        } else if (choice == 2) {
            char filename[512];
            printf("Enter the filename: ");
            fflush(stdout);
            if (scanf("%511s", filename + 256) != 1) {
                fprintf(stderr, "Invalid input\n");
                continue;
            }

            if (strstr(filename + 256, "..")) {
                fprintf(stderr, "Unsafe pattern detected!\n");
                continue;
            }

            if (filename[256] == '-') { 
                decode(filename + 257, filename, 256);
                if (_debug) {
                    printf("Decoded filename: %s\n", filename);
                }
            } else {
                strncpy(filename, filename + 256, 255);
                filename[255] = '\0';
            }
            snprintf(filename + 256, sizeof(filename) - 256, "./files/%s", filename);
            print_file(filename + 256);
        } else if (choice == 3) {
            puts("Exiting...");
            fflush(stdout);
            break;
        } else {
            puts("Invalid choice. Try again.");
        }
    }

    return 0;
}
```