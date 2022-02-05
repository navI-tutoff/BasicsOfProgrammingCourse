#include "vector.h"
#include <malloc.h>
#include <windows.h>

vector createVector(size_t n) {
    vector v;
    v.data = malloc(sizeof(int) * n);
    v.size = 0;
    v.capacity = n;

    if (v.data == NULL) {
        fprintf(stderr, "Bad alloc\n");
        exit(1);
    }

    return v;
}

void reverse(vector *v, size_t newCapacity) {
    v->capacity = newCapacity;

    if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    }

    v->data = realloc(v->data, sizeof(int) * newCapacity);

    if (v->data == NULL) {
        fprintf(stderr, "Bad alloc\n");
        exit(1);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}