```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>

#define MAX_FILENAME_LENGTH 256
#define DECODED_FILENAME_LENGTH 256
#define BASE64 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

void timeout_handler() {
    puts("\n\nTimeout expired!");
    exit(1);
}

void decode(char *input, char *output, size_t max_length) {
    size_t input_length = strlen(input);
    unsigned int buffer = 0;
    int bits_left = 0;
    size_t output_length = 0;

    for (size_t i = 0; i < input_length && output_length < max_length; i++) {
        char *encoded_char = strchr(BASE64, input[i]);
        if (encoded_char) {
            buffer = (buffer << 6) | (encoded_char - BASE64);
            bits_left += 6;

            if (bits_left >= 8) {
                bits_left -= 8;
                output[output_length++] = (char) ((buffer >> bits_left) & 0xFF);
            }
        }
    }
    output[output_length] = '\0';
}

void list_files() {
    DIR *dir = opendir("./files");
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    struct dirent *entry;
    puts("Files:");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            puts(entry->d_name);
        }
    }
    closedir(dir);
}

void print_file(const char *filename) {
    char buffer[256];
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

int main(int argc, char **argv) {
    char workdir[MAX_FILENAME_LENGTH] = ".";
    int timeout = 0;
    int debug = 0;

    int opt;
    while ((opt = getopt(argc, argv, "t:w:d")) != -1) {
        switch (opt) {
            case 't':
                timeout = atoi(optarg);
                break;
            case 'w':
                strncpy(workdir, optarg, MAX_FILENAME_LENGTH - 1);
                workdir[MAX_FILENAME_LENGTH - 1] = '\0';
                break;
            case 'd':
                debug = 1;
                break;
            default:
                fprintf(stderr, "Usage: %s -t <timeout> -w <workdir> [-d]\n", argv[0]);
                return 1;
        }
    }

    if (timeout) {
        signal(SIGALRM, timeout_handler);
        alarm(timeout);
    }

    chdir(workdir);

    char cwd[4096];
    getcwd(cwd, sizeof(cwd));
    if (debug) {
        printf("Running service in %s as user %d...\n", cwd, getuid());
    }

    while (1) {
        puts("Select an option:");
        puts("1. List files");
        puts("2. Read a file");
        puts("3. Exit");
        printf("Enter your choice: ");
        fflush(stdout);

        int choice;
        if (scanf("%d", &choice) == 1) {
            if (choice == 1) {
                list_files();
            } else if (choice == 2) {
                printf("Enter the filename: ");
                fflush(stdout);

                char input[MAX_FILENAME_LENGTH];
                scanf("%s", input);

                if (strstr(input, "..")) {
                    fwrite("Unsafe pattern detected!\n", 1, 26, stderr);
                    return 1;
                }

                char decoded[DECODED_FILENAME_LENGTH];
                if (input[0] == '~' && input[1] == 0) {
                    decode(input + 1, decoded, DECODED_FILENAME_LENGTH);
                    if (debug) {
                        printf("Decoded filename: %s\n", decoded);
                    }
                } else {
                    strncpy(decoded, input, DECODED_FILENAME_LENGTH - 1);
                    decoded[DECODED_FILENAME_LENGTH - 1] = '\0';
                }

                char filepath[512];
                snprintf(filepath, sizeof(filepath), "./files/%s", decoded);
                printf("Opening file %s\n", filepath);
                print_file(filepath);

            } else if (choice == 3) {
                puts("Exiting...");
                fflush(stdout);
                return 0;
            } else {
                puts("Invalid choice. Try again.");
            }
        } else {
            fwrite("Invalid input\n", 1, 14, stderr);
            while (getchar() != '\n');
        }
        fflush(stdout);
    }

    return 0;
}
```