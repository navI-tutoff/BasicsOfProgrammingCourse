#include "algorithms.h"

void swap(void *a, void *b, int size) {
    char *pa = a;
    char *pb = b;
    for (register int i = 0; i < size; i++) {
        char tmp = *pa;
        *pa = *pb;
        *pb = tmp;
        pa += 1;
        pb += 1;
    }
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}
