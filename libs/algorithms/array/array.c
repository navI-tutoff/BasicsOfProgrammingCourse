#include "array.h"
#include "../../algorithms/algorithms.h"

void inputArray(int *a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void outputArray(const int *a, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int linearSearch(const int *a, const int n, const int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int linearSearchIf(const int *a, const int n, bool (*f)(const int)) {
    for (int i = 0; i < n; i++) {
        if (f(a[i])) {
            return i;
        }
    }
    return -1;
}

int rLinearSearchIf(const int *a, const int n, bool (*f)(const int)) {
    for (int i = n - 1; i >= 0; i--) {
        if (f(a[i])) {
            return i;
        }
    }
    return -1;
}

int countIf(const int *a, const int n, bool (*f)(const int)) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (f(a[i])) {
            count++;
        }
    }
    return count;
}

void reverseArray(int *a, const int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        swap(&a[i], &a[j], sizeof(int));
    }
}

int isPalindromeArray(const int *a, const int n) {
    bool isPalindrome = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        if (a[i] == a[j]) {
            isPalindrome = 1;
        } else {
            isPalindrome = 0;
        }
    }
    return isPalindrome;
}

void selectionSort(int *a, const int n) {
    for (int i = 0; i < n - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minPos]) {
                minPos = j;
            }
        }
        swap(&a[i], &a[minPos], sizeof(int));
    }
}

void deleteIf(int *a, int *n, bool (*f)(const int)) {
    int iRead = 0;
    while (iRead < *n && !f(a[iRead])) {
        iRead++;
    }
    int iWrite = iRead;
    while (iRead < *n) {
        if (!f(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

void insertX(int *a, int *n, const int x, const int pos) {
    for (int i = *n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    a[pos] = x;
    (*n)++;
}

void append(int *a, int *n, const int x) {
    a[*n] = x;
    (*n)++;
}

void append_size_t(int *array, size_t *size, const int value) {
    *size += 1;
    array[*size - 1] = value;
}

void safeDelete(int *a, int *n, const int pos) {
    for (int i = pos; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

void unSafeDelete(int *a, int *n, const int pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

//void copyArray(const int *b, const int *a, size_t size) {
//    for (size_t i = 0; i < size; i++)
//        b[i] = a[i];
//}

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