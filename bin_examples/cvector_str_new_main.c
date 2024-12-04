#include "cvector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    cvector_str vec = {NULL, 0, 0};  // Initialize a string vector

    // Add strings to the vector
    cvec_push_str(&vec, "Hello");
    cvec_push_str(&vec, "World");
    cvec_push_str(&vec, "CVector");

    // Print strings in the vector
    for (size_t i = 0; i < vec.size; ++i) {
        printf("vec[%zu] = %s\n", i, vec.a[i]);
    }

    // Free the vector's resources
    cvec_free_str(&vec);

    return 0;
}
