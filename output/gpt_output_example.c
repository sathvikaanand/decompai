```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <math.h>
#include <unistd.h>

int timeout = 0;

void timeout_handler(int signal) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int main(int argc, char **argv) {
    char function[64];
    char parameter[64];
    double value, result;
    
    if (timeout != 0) {
        signal(SIGALRM, timeout_handler);
        alarm(timeout);
    }
    
    printf("Execution id: %p\n", (void *)main);
    printf("Please provide a mathematical function: ");
    fflush(stdout);
    
    if (fgets(function, sizeof(function), stdin) == NULL) {
        perror("fgets");
        return 1;
    }
    
    size_t len = strlen(function);
    if (len > 0 && function[len - 1] == '\n') {
        function[len - 1] = '\0';
    }
    
    printf("Please provide a parameter: ");
    fflush(stdout);
    
    if (fgets(parameter, sizeof(parameter), stdin) == NULL) {
        perror("fgets");
        return 1;
    }
    
    len = strlen(parameter);
    if (len > 0 && parameter[len - 1] == '\n') {
        parameter[len - 1] = '\0';
    }
    
    value = atof(parameter);
    
    if (strcmp(function, "abs") == 0) {
        result = fabs(value);
    } else if (strcmp(function, "sinh") == 0) {
        result = sinh(value);
    } else if (strcmp(function, "cosh") == 0) {
        result = cosh(value);
    } else if (strcmp(function, "tanh") == 0) {
        result = tanh(value);
    } else {
        printf("Unknown function %s!\n", function);
        return 1;
    }
    
    printf("The application of %s to %s returned %f\n", function, parameter, result);
    return 0;
}
```