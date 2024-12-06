```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>

void timeout_handler(void) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int main(void) {
    char function[64];
    char parameter[64];
    char result_message[1023];

    signal(SIGALRM, timeout_handler);
    alarm(10);

    printf("Execution id: %p\n", main);
    printf("Please provide a mathematical function: ");
    fflush(stdout);
    
    if (fgets(function, sizeof(function), stdin) != NULL) {
        size_t len = strlen(function);
        if (function[len - 1] == '\n') {
            function[len - 1] = '\0';
        }

        printf("Please provide a parameter: ");
        fflush(stdout);

        if (fgets(parameter + 1, sizeof(parameter) - 1, stdin) != NULL) {
            len = strlen(parameter + 1);
            if (parameter[len] == '\n') {
                parameter[len] = '\0';
            }

            double param_value = atof(parameter + 1);
            double result = 0;

            if (strcmp(function, "sin") == 0) {
                result = sinh(param_value);
            } else if (strcmp(function, "cos") == 0) {
                result = cosh(param_value);
            } else if (strcmp(function, "tan") == 0) {
                result = tanh(param_value);
            } else {
                printf("Unknown function %s!\n", function);
                return 1;
            }
            
            snprintf(result_message, sizeof(result_message), "The application of %s to %s returned %f\n", function, parameter + 1, result);
            parameter[0] = '\0';
            printf("%s", result_message);
            return 0;
        }
    }

    perror("fgets");
    return 1;
}
```