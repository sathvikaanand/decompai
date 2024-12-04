#include "cvector.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    cvector_i vec = {NULL, 0, 0};  // Initialize vector

    // Add elements
    for (int i = 0; i < 5; ++i) {
        if (vec.size == vec.capacity) {
            vec.capacity = vec.capacity == 0 ? 1 : vec.capacity * 2;
            vec.a = realloc(vec.a, vec.capacity * sizeof(int));
        }
        vec.a[vec.size++] = i;
    }

    // Print elements
    for (cvec_sz i = 0; i < vec.size; ++i) {
        printf("vec[%zu] = %d\n", i, vec.a[i]);
    }

    // Free memory
    free(vec.a);
    vec.a = NULL;
    vec.size = 0;
    vec.capacity = 0;

    return 0;
}
