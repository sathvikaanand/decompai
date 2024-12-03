Here's the C source code that closely resembles the functionality and logic present in the provided Ghidra decompiled pseudocode, while omitting the unnecessary boilerplate and library initialization code.

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void timeout_handler(int param_1) {
    puts("\n\nTimeout expired!");
    exit(1);
}

int main(void) {
    char function_name[64];
    char parameter_input[65];
    char output_message[1024];
    double parameter_value;
    double result;
    
    int timeout = 10; // Set your desired timeout duration here
    if (timeout != 0) {
        signal(SIGALRM, timeout_handler);
        alarm(timeout);
    }

    printf("Execution id: %p\n", output_message);
    printf("Please provide a mathematical function: ");
    fflush(stdout);
    
    if (fgets(function_name, sizeof(function_name), stdin) == NULL) {
        perror("fgets");
        return 1;
    }

    // Remove newline character
    size_t len = strlen(function_name);
    if (function_name[len - 1] == '\n') {
        function_name[len - 1] = '\0';
    }

    printf("Please provide a parameter: ");
    fflush(stdout);
    
    if (fgets(parameter_input, sizeof(parameter_input), stdin) == NULL) {
        perror("fgets");
        return 1;
    }

    // Remove newline character
    len = strlen(parameter_input);
    if (parameter_input[len - 1] == '\n') {
        parameter_input[len - 1] = '\0';
    }

    parameter_value = atof(parameter_input);

    if (strcmp(function_name, "abs") == 0) {
        result = fabs(parameter_value); // Using <math.h> for absolute value
    } 
    else if (strcmp(function_name, "sinh") == 0) {
        result = sinh(parameter_value);
    } 
    else if (strcmp(function_name, "cosh") == 0) {
        result = cosh(parameter_value);
    } 
    else if (strcmp(function_name, "tanh") == 0) {
        result = tanh(parameter_value);
    } 
    else {
        printf("Unknown function %s!\n", function_name);
        return 1;
    }

    snprintf(output_message, sizeof(output_message), "The application of %s to %s returned %f\n", function_name, parameter_input, result);
    printf("%s", output_message);

    return 0;
}
```

### Key Transformations:
1. **Function Names and Parameters**: The names of the input parameters and functions have been directly mapped, maintaining clarity in what the code aims to achieve.
2. **Library Functions**: Only the necessary standard library functions have been included.
3. **Signal Handling**: A simple signal handler has been created for handling timeout durations without any complicated initial setup or unused code.
4. **Error Handling**: Appropriate error checks are included using `perror` for input handling.
5. **String Management**: Handling for newline character removal from input strings was added to ensure the output formatting stays consistent.
6. **Calculation Logic**: Mathematical function handling is streamlined for readability and maintainability.
  
This C code implements the same logic as depicted in the provided pseudocode, ensuring it functions as intended without the overhead of decompiled artifacts.