#include <stdio.h>

void funcA(int a, int b) {
    printf("Function A: %d + %d = %d\n", a, b, a + b);
}

void funcB(int a, int b) {
    printf("Function B: %d * %d = %d\n", a, b, a * b);
}

int main() {
    void (*func_ptrs[2])(int, int);
    int (*arr)[2];
    
    // Initialize function pointers
    func_ptrs[0] = funcA;
    func_ptrs[1] = funcB;

    // Pointer arithmetic on an array of function pointers
    arr = (int(*)[2])func_ptrs;

    // Using the function pointer array with offset
    (*((void(**)(int, int))arr + 0))(10, 5);  // Calls funcA
    (*((void(**)(int, int))arr + 1))(10, 5);  // Calls funcB

    return 0;
}

