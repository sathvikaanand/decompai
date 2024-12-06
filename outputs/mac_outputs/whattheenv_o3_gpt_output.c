```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <wordexp.h>

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int main(int argc, char *argv[]) {
    char *workdir = NULL;
    int timeout = 0;
    int debug = 0;
    int opt;
    char input[4096];
    char var_name[16], var_value[512];
    char command[17];
    
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

    if (workdir && chdir(workdir) != 0) {
        perror("chdir");
        return 1;
    }

    getcwd(input, sizeof(input));
    if (debug) {
        printf("Running service in %s as user %d...\n", input, getuid());
    }

    umask(0);
    if (!mkdtemp(input)) {
        perror("mkdtemp");
        return 1;
    }
    if (chdir(input) != 0) {
        perror("chdir");
        return 1;
    }

    printf("Your service ID is %s\n", input);
    fflush(stdout);

    while (1) {
        printf("Command (load/store/quit): ");
        fflush(stdout);
        if (!fgets(command, sizeof(command), stdin)) {
            perror("fgets");
            return 1;
        }

        size_t len = strlen(command);
        if (command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        if (strcmp(command, "load") == 0) {
            printf("Please enter a variable: ");
            fflush(stdout);
            if (!fgets(var_name, sizeof(var_name), stdin)) {
                perror("fgets");
                return 1;
            }
            var_name[strcspn(var_name, "\n")] = '\0';

            printf("Please enter a value: ");
            fflush(stdout);
            if (!fgets(var_value, sizeof(var_value), stdin)) {
                perror("fgets");
                return 1;
            }
            var_value[strcspn(var_value, "\n")] = '\0';

            setenv(var_name, var_value, 1);

        } else if (strncmp(command, "store", 5) == 0) {
            printf("Please enter a variable: ");
            fflush(stdout);
            if (!fgets(var_name, sizeof(var_name), stdin)) {
                perror("fgets");
                return 1;
            }
            var_name[strcspn(var_name, "\n")] = '\0';

            char *env_value = getenv(var_name);
            if (!env_value) {
                puts("Non-existent variable!");
                fflush(stdout);
                continue;
            }

            wordexp_t p;
            wordexp("~/permissions", &p, 0);
            FILE *perm_file = fopen(p.we_wordv[0], "r");
            if (!perm_file) {
                perm_file = fopen(p.we_wordv[0], "w+");
                if (!perm_file) {
                    perror("fopen");
                    return 1;
                }
                fwrite("0600", 4, 1, perm_file);
                rewind(perm_file);
            }

            char perms[5];
            fread(perms, 1, 4, perm_file);
            perms[4] = '\0';
            unsigned long mode = strtoul(perms, NULL, 8);
            fclose(perm_file);

            FILE *var_file = fopen(var_name, "w+");
            if (!var_file) {
                perror("fopen");
                return 1;
            }
            fwrite(env_value, strlen(env_value), 1, var_file);
            fclose(var_file);

            if (chmod(var_name, mode) != 0) {
                perror("chmod");
            }

            puts("Variable value saved!");
            fflush(stdout);

        } else if (strcmp(command, "quit") == 0) {
            puts("Currently saved values:");
            execlp("ls", "ls", NULL);
            exit(0);

        } else {
            puts("Unknown command!");
        }
    }

    return 0;
}
```