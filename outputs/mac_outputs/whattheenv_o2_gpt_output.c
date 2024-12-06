```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wordexp.h>

volatile int timeout = 0;
volatile int debug = 0;

void timeout_handler() {
    printf("\n\nTimeout expired!");
    exit(1);
}

int main(int argc, char *argv[]) {
    int opt;
    char *workdir = NULL;
    char currentDir[4096];
    char tmpTemplate[] = "idXXXXXX";
    char command[17];
    char variable[16];
    char value[512];
    FILE *file;
    wordexp_t p;
    mode_t perms;
    size_t len;

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
                exit(1);
        }
    }

    if (timeout != 0) {
        signal(SIGALRM, timeout_handler);
        alarm(timeout);
    }

    if (workdir != NULL) {
        chdir(workdir);
    }

    getcwd(currentDir, sizeof(currentDir));
    if (debug) {
        printf("Running service in %s as user %d...\n", currentDir, getuid());
    }

    umask(0);

    if (mkdtemp(tmpTemplate) == NULL) {
        perror("mkdtemp");
        exit(1);
    }

    if (chdir(tmpTemplate) != 0) {
        perror("chdir");
        exit(1);
    }

    printf("Your service ID is %s\n", tmpTemplate);
    fflush(stdout);

    while (1) {
        printf("Command (load/store/quit): ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("fgets");
            exit(1);
        }

        len = strlen(command);

        if (command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        if (strcmp(command, "load") == 0) {
            printf("Please enter a variable: ");
            fflush(stdout);

            if (fgets(variable, sizeof(variable), stdin) == NULL) {
                perror("fgets");
                exit(1);
            }

            len = strlen(variable);

            if (variable[len - 1] == '\n') {
                variable[len - 1] = '\0';
            }

            printf("Please enter a value: ");
            fflush(stdout);

            if (fgets(value, sizeof(value), stdin) == NULL) {
                perror("fgets");
                exit(1);
            }

            len = strlen(value);

            if (value[len - 1] == '\n') {
                value[len - 1] = '\0';
            }

            setenv(variable, value, 1);

        } else if (strcmp(command, "store") == 0) {
            printf("Please enter a variable: ");
            fflush(stdout);

            if (fgets(variable, sizeof(variable), stdin) == NULL) {
                perror("fgets");
                exit(1);
            }

            len = strlen(variable);

            if (variable[len - 1] == '\n') {
                variable[len - 1] = '\0';
            }

            char *env_var = getenv(variable);

            if (env_var == NULL) {
                printf("Non-existent variable!\n");
                fflush(stdout);
            } else {
                if (wordexp("~/permissions", &p, 0) != 0) {
                    perror("wordexp");
                    exit(1);
                }

                file = fopen(p.we_wordv[0], "r");
                if (file == NULL) {
                    perror("fopen");
                } else {
                    if (fread(&perms, 1, sizeof(perms), file) != sizeof(perms)) {
                        perror("fread");
                    }

                    fclose(file);
                }

                size_t var_len = strlen(env_var);

                file = fopen(variable, "w+");
                if (file == NULL) {
                    perror("fopen");
                } else {
                    fwrite(env_var, 1, var_len, file);
                    fclose(file);

                    if (chmod(variable, perms) != 0) {
                        perror("chmod");
                    } else {
                        printf("Variable value saved!\n");
                        fflush(stdout);
                    }
                }
                wordfree(&p);
            }

        } else if (strcmp(command, "quit") == 0) {
            printf("Currently saved values:\n");
            execlp("ls", "ls", NULL);
            exit(0);
        } else {
            printf("Unknown command!\n");
            fflush(stdout);
        }
    }

    return 0;
}
```