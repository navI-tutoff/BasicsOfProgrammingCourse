#include "ordered_array_set.h"
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

int binarySearch(const int *a, int n, int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return a[left] == x ? left : n;
}

int binarySearchLessOrEqual(const int *a, const int n, const int x) {
    int left = -1;
    int right = n;

    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return left;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch(set->data, set->size, value);
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size, size_t capacity) {
    ordered_array_set set = ordered_array_set_create(capacity);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);

    return set;
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;

    for (size_t i = 0; i < set1.size; i++)
        if (set1.data[i] != set2.data[i])
            return false;

    return true;
}


bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    if (subset.size == 0)
        return true;

    for (size_t i = 0; i < subset.size; i++) {
        if (ordered_array_set_in(&set, subset.data[i]) == set.size)
            return 0;
    }

    return 1;
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    bool isEmpty = true;
    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
        isEmpty = false;
    }
    if (isEmpty)
        printf("}");
    else
        printf("\b\b}");

    printf("\n");
}

void insert(int *const a, size_t *const n, const size_t pos, const int value) {
    if (*n == pos) {
        append_size_t(a, n, value);
        return;
    }
    (*n)++;
    for (size_t i = *n; i != pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos] = value;
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(set, value) == set->size) {
        int positionInsert = binarySearchLessOrEqual(set->data, set->size, value);
        if (positionInsert == -1)
            insert(set->data, &set->size, 0, value);
        else
            insert(set->data, &set->size, positionInsert + 1, value);
    }
}

void safeDelete(int *a, int *n, const int pos) {
    for (int i = pos; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) != set->size) {
        size_t indexDelete = binarySearch(set->data, set->size, value);
        safeDelete(set->data, &set->size, indexDelete);
    }
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);

    size_t i = 0;
    size_t j = 0;
    while (j < set2.size && i < set1.size) {
        if (set2.data[j] < set1.data[i]) {
            append_size_t(set3.data, &set3.size, set2.data[j]);
            j++;
        } else if (set2.data[j] > set1.data[i]) {
            append_size_t(set3.data, &set3.size, set1.data[i]);
            i++;
        }
        else {
            j++;
        }
    }

    while (j < set2.size) {
        append_size_t(set3.data, &set3.size, set2.data[j++]);
    }
    while (i < set1.size) {
        append_size_t(set3.data, &set3.size, set1.data[i++]);
    }

    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);

    size_t i = 0;
    size_t j = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] > set2.data[j]) {
            j++;
        } else if (set1.data[i] < set2.data[j]) {
            i++;
        } else {
            append_size_t(set3.data, &set3.size, set1.data[i++]);
            j++;
        }
    }
    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    size_t i = 0;
    size_t j = 0;
    int capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);

    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            append_size_t(set3.data, &set3.size, set1.data[i++]);
        } else if (set1.data[i] == set2.data[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (size_t k = i; k < set1.size; k++) {
        append_size_t(set3.data, &set3.size, set1.data[k]);
    }

    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set3 = ordered_array_set_union(ordered_array_set_difference(set1, set2),
                                                     ordered_array_set_difference(set2, set1));

    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    return (ordered_array_set) ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}