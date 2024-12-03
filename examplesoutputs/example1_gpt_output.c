```c
#include <stdio.h>

int main() {
    unsigned int num1, num2;
    
    // Ask the user for input
    printf("Enter the first number: ");
    scanf("%u", &num1);

    printf("Enter the second number: ");
    scanf("%u", &num2);

    // Calculate and display the sum
    printf("The sum of %u and %u is: %u\n", num1, num2, num1 + num2);

    return 0;
}
```