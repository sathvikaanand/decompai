```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <pwd.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <wordexp.h>

int timeout = 0;
int debug = 0;

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

bool main_cold_1(char *param_1, FILE **param_2) {
    FILE *pFVar2;

    puts("Cannot find the permission file");
    perror("fopen");
    fflush(stdout);
    printf("Creating permission file %s\n", param_1);
    pFVar2 = fopen(param_1, "w+");
    *param_2 = pFVar2;
    if (pFVar2 == NULL) {
        perror("fopen");
        puts("Cannot create the file permissions spec");
        fflush(stdout);
    } else {
        fwrite("0600", 4, 1, pFVar2);
        rewind(pFVar2);
    }
    return pFVar2 == NULL;
}

int main(int argc, char *argv[]) {
    char *optarg = NULL;
    int opt, iVar3, iVar4;
    size_t sVar5;
    FILE *pFVar6;
    ulong uVar7;
    char *workdir = NULL;
    char *pcVar9;
    char *pcVar10;
    wordexp_t wStack_12c8;
    char acStack_12ad[4];
    FILE *local_12a8;
    char acStack_12a0[4096];
    char local_2a0[] = "XXXXXX";
    int local_290;
    short local_28c;
    char acStack_281[512];
    char acStack_81[17];
    long local_70;
    
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
        signal(SIGALRM, (void (*)(int))timeout_handler);
        alarm(timeout);
    }
    if (workdir != NULL) {
        chdir(workdir);
    }
    getcwd(acStack_12a0, 4096);
    if (debug) {
        printf("Running service %s in %s as user %d...\n", argv[0], acStack_12a0, getuid());
    }
    umask(0);
    pcVar9 = mkdtemp(local_2a0);
    if (pcVar9 == NULL) {
        perror("mkdtemp");
        exit(1);
    }
    if (chdir(pcVar9) != 0) {
        perror("chdir");
        exit(1);
    }
    printf("Your service ID is %s\n", local_2a0);
    fflush(stdout);

    while (true) {
        printf("Command (load/store/quit): ");
        fflush(stdout);
        if (fgets((char *)&local_290, 0x10, stdin) == NULL) {
            perror("fgets");
            exit(1);
        }
        sVar5 = strlen((char *)&local_290);
        if (((char *)&local_290)[sVar5] == '\n') {
            ((char *)&local_290)[sVar5] = '\0';
        }
        if (local_290 == 0x64616f6c && (char)local_28c == '\0') {
            printf("Please enter a variable: ");
            fflush(stdout);
            if (fgets(acStack_81 + 1, 0x10, stdin) == NULL) {
                perror("fgets");
                exit(1);
            }
            sVar5 = strlen(acStack_81 + 1);
            if (acStack_81[sVar5] == '\n') {
                acStack_81[sVar5] = '\0';
            }
            printf("Please enter a value: ");
            fflush(stdout);
            if (fgets(acStack_281 + 1, 0x200, stdin) == NULL) {
                perror("fgets");
                exit(1);
            }
            sVar5 = strlen(acStack_281 + 1);
            if (acStack_281[sVar5] == '\n') {
                acStack_281[sVar5] = '\0';
            }
            setenv(acStack_81 + 1, acStack_281 + 1, 1);
        } else if (local_290 == 0x726f7473 && local_28c == 0x65) {
            printf("Please enter a variable: ");
            fflush(stdout);
            if (fgets(acStack_81 + 1, 0x10, stdin) == NULL) {
                perror("fgets");
                exit(1);
            }
            sVar5 = strlen(acStack_81 + 1);
            if (acStack_81[sVar5] == '\n') {
                acStack_81[sVar5] = '\0';
            }
            pcVar9 = getenv(acStack_81 + 1);
            if (pcVar9 == NULL) {
                puts("Non-existent variable!");
                fflush(stdout);
            } else {
                wordexp("~/permissions", &wStack_12c8, 0);
                pcVar10 = *wStack_12c8.we_wordv;
                printf("Opening permission file %s\n", pcVar10);
                pFVar6 = fopen(pcVar10, "r");
                if (pFVar6 == NULL && main_cold_1(pcVar10, &local_12a8)) {
                    pFVar6 = local_12a8;
                }
                fread(acStack_12ad, 1, 4, pFVar6);
                uVar7 = strtoul(acStack_12ad, NULL, 8);
                pFVar6 = fopen(acStack_81 + 1, "w+");
                fwrite(pcVar9, strlen(pcVar9), 1, pFVar6);
                fclose(pFVar6);
                if (chmod(acStack_81 + 1, (mode_t)uVar7) != 0) {
                    perror("chmod");
                }
                puts("Variable value saved!");
                fflush(stdout);
            }
        } else if (local_290 == 0x74697571) {
            puts("Currently saved values:");
            execlp("ls", "ls", (char *)NULL);
        } else {
            puts("Unknown command!");
        }
    }
    return 0;
}
```
