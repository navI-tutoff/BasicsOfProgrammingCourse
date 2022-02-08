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

bool isEmpty(vector *v) {
    return v->size == 0 ? 1 : 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        v->capacity++;
    } else if (isFull(v)) {
        v->capacity *= 2;
    }
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is already empty");
        exit(1);
    }
    v->size--;
}