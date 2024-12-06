```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CVEC_STR_START_SZ 4

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} CVector;

void cvec_initialize(CVector *vec, size_t initial_capacity) {
    vec->size = 0;
    vec->capacity = initial_capacity + CVEC_STR_START_SZ;
    vec->data = malloc(vec->capacity * sizeof(char *));
    if (vec->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void cvec_push_str(CVector *vec, const char *str) {
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(char *));
        if (vec->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    vec->data[vec->size] = strdup(str);
    if (vec->data[vec->size] == NULL) {
        fprintf(stderr, "String duplication failed\n");
        exit(EXIT_FAILURE);
    }
    vec->size++;
}

void cvec_free(CVector *vec) {
    for (size_t i = 0; i < vec->size; i++) {
        free(vec->data[i]);
    }
    free(vec->data);
}

void entry(void) {
    CVector vec;
    cvec_initialize(&vec, 3);

    cvec_push_str(&vec, "Hello");
    cvec_push_str(&vec, "World");
    cvec_push_str(&vec, "CVector");

    for (size_t i = 0; i < vec.size; i++) {
        printf("vec[%zu] = %s\n", i, vec.data[i]);
    }

    cvec_free(&vec);
}

int main(void) {
    entry();
    return 0;
}
```