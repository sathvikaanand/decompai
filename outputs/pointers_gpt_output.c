```c
#include <stdio.h>

void functionA(unsigned int param1, unsigned int param2) {
    printf("Function A: %d + %d = %d\n", param1, param2, param1 + param2);
}

void functionB(unsigned int param1, unsigned int param2) {
    printf("Function B: %d * %d = %d\n", param1, param2, param1 * param2);
}

int main() {
    functionA(10, 5);
    functionB(10, 5);
    return 0;
}
```