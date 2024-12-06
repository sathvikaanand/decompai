```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>

void timeout_handler(int signal) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int main(int argc, char **argv) {
    char input_function[64];
    char input_parameter[64];
    double parameter_value;
    char output[1024];

    // Setup a timeout handler
    signal(SIGALRM, timeout_handler);
    unsigned int timeout = 5;
    alarm(timeout);

    printf("Execution id: %p\n", (void*)main);
    printf("Please provide a mathematical function (abs, sinh, cosh, tanh): ");
    fflush(stdout);

    if (fgets(input_function, sizeof(input_function), stdin) == NULL) {
        perror("fgets");
        return 1;
    }

    size_t len = strlen(input_function);
    if (len > 0 && input_function[len - 1] == '\n') {
        input_function[len - 1] = '\0';
    }

    printf("Please provide a parameter: ");
    fflush(stdout);

    if (fgets(input_parameter, sizeof(input_parameter), stdin) == NULL) {
        perror("fgets");
        return 1;
    }

    len = strlen(input_parameter);
    if (len > 0 && input_parameter[len - 1] == '\n') {
        input_parameter[len - 1] = '\0';
    }

    parameter_value = atof(input_parameter);
    double result = 0.0;

    if (strcmp(input_function, "abs") == 0) {
        result = fabs(parameter_value);
    } else if (strcmp(input_function, "sinh") == 0) {
        result = sinh(parameter_value);
    } else if (strcmp(input_function, "cosh") == 0) {
        result = cosh(parameter_value);
    } else if (strcmp(input_function, "tanh") == 0) {
        result = tanh(parameter_value);
    } else {
        printf("Unknown function %s!\n", input_function);
        return 1;
    }

    snprintf(output, sizeof(output), "The application of %s to %s returned %f\n", input_function, input_parameter, result);
    printf("%s", output);

    return 0;
}
```