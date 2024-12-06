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
    char function_name[65];
    char parameter_str[64];
    char output[1023];
    double parameter = 0.0;
    double result = 0.0;

    if (timeout != 0) {
        signal(SIGALRM, timeout_handler);
        alarm(timeout);
    }

    printf("Execution id: %p\n", output);
    printf("Please provide a mathematical function: ");
    fflush(stdout);
    if (fgets(function_name, sizeof(function_name), stdin) == NULL) {
        perror("fgets");
        return 1;
    }

    // Remove the newline character if present
    function_name[strcspn(function_name, "\n")] = 0;

    printf("Please provide a parameter: ");
    fflush(stdout);
    if (fgets(parameter_str, sizeof(parameter_str), stdin) == NULL) {
        perror("fgets");
        return 1;
    }

    // Remove the newline character if present
    parameter_str[strcspn(parameter_str, "\n")] = 0;

    parameter = atof(parameter_str);

    if (strcmp(function_name, "abs") == 0) {
        result = fabs(parameter);
    } else if (strcmp(function_name, "sinh") == 0) {
        result = sinh(parameter);
    } else if (strcmp(function_name, "cosh") == 0) {
        result = cosh(parameter);
    } else if (strcmp(function_name, "tanh") == 0) {
        result = tanh(parameter);
    } else {
        printf("Unknown function %s!\n", function_name);
        return 1;
    }

    snprintf(output, sizeof(output), "The application of %s to %s returned %f\n",
             function_name, parameter_str, result);
    printf("%s", output);
    return 0;
}
```