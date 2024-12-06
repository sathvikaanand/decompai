```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>

// Global variables for options
int debug = 0;
int timeout = 0;

// Function prototypes
void timeout_handler(void);
void decode(char *param_1, long param_2, unsigned long param_3);
void list_files(void);
void print_file(char *filename);

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

void decode(char *input, long output_buf, unsigned long output_size) {
    const char *lookup_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    size_t len = strlen(input);
    unsigned int buffer = 0;
    int bits_left = 0;
    unsigned long output_len = 0;

    for (size_t i = 0; i < len && output_len < output_size; ++i) {
        char *pos = strchr(lookup_table, input[i]);
        if (pos) {
            buffer = (buffer << 6) | (pos - lookup_table);
            bits_left += 6;
            if (bits_left >= 8) {
                bits_left -= 8;
                ((char *)output_buf)[output_len++] = (buffer >> bits_left) & 0xFF;
            }
        }
    }

    ((char *)output_buf)[output_len] = '\0';
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
        if (entry->d_name[0] != '.') {
            puts(entry->d_name);
        }
    }
    closedir(dir);
}

void print_file(char *filename) {
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

int main(int argc, char *argv[]) {
    int opt;
    char *workdir = NULL;

    while ((opt = getopt(argc, argv, "t:w:d")) != -1) {
        switch (opt) {
            case 't':
                timeout = atoi(optarg);
                break;
            case 'w':
                workdir = strdup(optarg);
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

    if (workdir) {
        chdir(workdir);
    }

    char cwd[4096];
    getcwd(cwd, sizeof(cwd));
    if (debug) {
        printf("Running service in %s as user %d...\n", cwd, getuid());
    }

    int choice;
    while (1) {
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
            if (scanf("%s", filename + 256) == 1) {
                if (strstr(filename + 256, "..")) {
                    fwrite("Unsafe pattern detected!\n", 1, 25, stderr);
                    continue;
                }
                if (filename[256] == '-' && filename[257] == '0' && filename[258] == 'x') {
                    decode(filename + 259, (long)filename, 256);
                    if (debug) printf("Decoded filename: %s\n", filename);
                } else {
                    strncpy(filename, filename + 256, 255);
                    filename[255] = '\0';
                }
                snprintf(filename + 512, sizeof(filename) - 512, "./files/%s", filename);
                printf("Opening file %s\n", filename + 512);
                print_file(filename + 512);
                fflush(stdout);
            }
        } else if (choice == 3) {
            puts("Exiting...");
            fflush(stdout);
            break;
        } else {
            puts("Invalid choice. Try again.");
            fflush(stdout);
        }
    }

    return 0;
}
```