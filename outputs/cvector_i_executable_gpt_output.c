```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 4

int main() {
    size_t capacity = INITIAL_SIZE;
    size_t size = 0;
    int* array = (int*)malloc(capacity * sizeof(int));
    
    if (!array) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        if (size == capacity) {
            capacity *= 2;
            array = (int*)realloc(array, capacity * sizeof(int));
            if (!array) {
                fprintf(stderr, "Memory reallocation failed\n");
                return 1;
            }
        }
        array[size++] = i;
    }

    for (size_t i = 0; i < size; i++) {
        printf("vec[%zu] = %d\n", i, array[i]);
    }

    free(array);
    return 0;
}
```