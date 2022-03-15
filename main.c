//#include "libs/data_structures/ordered_array_set/ordered_array_set.h"
//
//#define ARRAY_SIZE_A 4
//#define ARRAY_SIZE_B 4
//#define ARRAY_SIZE_C 4
//
//#define ARRAY_SIZE_A2 7
//#define ARRAY_SIZE_B2 5
//#define ARRAY_SIZE_C2 5
//#define ARRAY_SIZE_D2 5
//
//int main() {
//    ///     задания 4-5 для пункта 1
//    printf("First Task \n \n");
//
//    int a[ARRAY_SIZE_A] = {1, 2, 3, 8};
//    ordered_array_set arraySetA = ordered_array_set_create_from_array(a, ARRAY_SIZE_A, ARRAY_SIZE_A);
//
//    int b[ARRAY_SIZE_B] = {3, 5, 6, 7};
//    ordered_array_set arraySetB = ordered_array_set_create_from_array(b, ARRAY_SIZE_B, ARRAY_SIZE_B);
//
//    int c[ARRAY_SIZE_C] = {2, 3, 4, 7};
//    ordered_array_set arraySetC = ordered_array_set_create_from_array(c, ARRAY_SIZE_C, ARRAY_SIZE_C);
//
//    ordered_array_set firstStep = ordered_array_set_intersection(arraySetA, arraySetB);
//    ordered_array_set secondStep = ordered_array_set_difference(arraySetA, arraySetC);
//    ordered_array_set thirdStep = ordered_array_set_difference(arraySetB, arraySetC);
//    ordered_array_set fourthStep = ordered_array_set_union(firstStep, secondStep);
//    ordered_array_set fifthStep = ordered_array_set_union(fourthStep, thirdStep);
//
//    printf("Result of firstStep - ");
//    ordered_array_set_print(firstStep);
//    printf("Result of secondStep - ");
//    ordered_array_set_print(secondStep);
//    printf("Result of thirdStep - ");
//    ordered_array_set_print(thirdStep);
//    printf("Result of fourthStep - ");
//    ordered_array_set_print(fourthStep);
//    printf("Result of fifthStep - ");
//    ordered_array_set_print(fifthStep);
//
//    printf("\n");
//
//    ///     задания 4-5 для пункта 2
//    printf("Second Task \n \n");
//
//    int a2[ARRAY_SIZE_A2] = {1, 2, 3, 4, 5, 6, 7};
//    ordered_array_set arraySetA2 = ordered_array_set_create_from_array(a2, ARRAY_SIZE_A2, ARRAY_SIZE_A2);
//
//    int b2[ARRAY_SIZE_B2] = {2, 5, 6, 9, 10};
//    ordered_array_set arraySetB2 = ordered_array_set_create_from_array(b2, ARRAY_SIZE_B2, ARRAY_SIZE_B2);
//
//    int c2[ARRAY_SIZE_C2] = {4, 7, 8, 11, 12};
//    ordered_array_set arraySetC2 = ordered_array_set_create_from_array(c2, ARRAY_SIZE_C2, ARRAY_SIZE_C2);
//
//    int d2[ARRAY_SIZE_D2] = {2, 5, 6, 7, 4};
//    ordered_array_set arraySetD2 = ordered_array_set_create_from_array(d2, ARRAY_SIZE_D2, ARRAY_SIZE_D2);
//
//    ordered_array_set firstStep2 = ordered_array_set_intersection(arraySetA2, arraySetB2);
//    ordered_array_set secondStep2 = ordered_array_set_intersection(arraySetA2, arraySetC2);
//    ordered_array_set thirdStep2 = ordered_array_set_union(firstStep2, secondStep2);
//
//    ordered_array_set_print(thirdStep2);
//
//    if (ordered_array_set_isEqual(thirdStep2, arraySetD2)) {
//        printf("Expected and gotten sets are equal \n");
//    } else {
//        printf("Expected and gotten sets are different \n");
//    }
//
//    return 0;
//}

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

//#include "libs/algorithms/array/array.h"
#include "libs/algorithms/algorithms.h"

#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock(); \
    testCode \
        clock_t end_time = clock(); \
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC; \
}

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// функция сортировки
typedef struct SortFunc {
    void (*sort)(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64];                  // имя сортировки
    // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate)(int *a, size_t n); // указатель на функцию
    // генерации последоват.
    char name[64];                      // имя генератора,
    // используемое при выводе
} GeneratingFunc;

bool isOrdered(const int *a, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }

    return true;
}

//double getTime() {
//    clock_t start_time = clock();
//    // фрагмент кода
//    // время которого измеряется
//    clock_t end_time = clock();\
//    clock_t sort_time = end_time - start_time;
//    return (double) sort_time / CLOCKS_PER_SEC;
//}

void outputArray(const int *a, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void checkTime(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;
// генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf(" Name : %s\n", experimentName);

    // замер времени
    double time;
    TIME_TEST
    ({
         sortFunc(innerBuffer, size);
     }, time);

    // результаты замера
    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

        // запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");
        // вывод массива, который не смог быть отсортирован
        outputArray(innerBuffer, size);
        exit(1);
    }
}

/*
 *
 * int d = rand () % a ; // генерация чисел от 0 до a - 1
 * int e = rand () + b ; // генерация чисел от b до RAND_MAX + b
 * int f = rand () % b + a ; // генерация чисел от a до a + b - 1
 * int g = a + rand () % ( b - a + 1) ; // генерация чисел от a до b

 */

int cmp_int(const void *a, const void *b) {
    return *(const int *) a - *(const int *) b;
}

int cmp_intR(const void *a, const void *b) {
    return *(const int *) b - *(const int *) a;
}

void generateRandomArray(int *a, size_t size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        a[i] = rand() % INT_MAX;
    }
}

void generateOrderedArray(int *a, size_t size) {
    generateRandomArray(a, size);
    qsort(a, size, sizeof(int), cmp_int);
}

void generateOrderedBackwards(int *a, size_t size) {
    generateRandomArray(a, size);
    qsort(a, size, sizeof(int), cmp_intR);
}

// sorts

void selectionSort(int *a, size_t size) { // сортировка выбором
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minPos]) {
                minPos = j;
            }
        }
        swap(&a[i], &a[minPos], sizeof(int));
    }
}

void insertionSort(int *a, size_t size) { // сортировка вставками
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void bubbleSort(int *a, size_t size) { // сортировка обменом
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j], sizeof(int));
            }
        }
}

void combSort(int *a, const size_t size) { // сортировка расческой
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1) {
            step /= 1.24733;
        }
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j], sizeof(int));
                swapped = 1;
            }
        }
    }
}

void getMinMax(const int *a, size_t size, int *min, int *max) {
    *min = a[0];
    *max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < *min)
            *min = a[i];
        else if (a[i] > *max)
            *max = a[i];
    }
}

// laba pro copypast xD
void countSort(int *a, const size_t size) { // сортировка подсчётом
    int min, max;
    getMinMax(a, size, &min, &max);
    int k = max - min + 1;

    int *b = (int *) calloc(k, sizeof(int));
    for (int i = 0; i < size; i++) {
        b[a[i] - min]++;
    }
    int ind = 0;
    for (int i = 0; i < k; i++) {
        int x = b[i];
        for (int j = 0; j < x; j++) {
            a[ind++] = min + i;
        }
    }
    free(b);
}

#include <memory.h>

void merge(const int *a, const size_t n,
           const int *b, const size_t m, int *c) {
    int i = 0, j = 0;
    while (i < n || j < m) {
        if (j == m || i < n && a[i] < b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
    }
}

void mergeSort_(int *source, size_t l, size_t r, int *buffer) {
    size_t n = r - l;
    if (n <= 1) {
        return;
    }

    size_t m = (l + r) / 2;
    mergeSort_(source, l, m, buffer);
    mergeSort_(source, m, r, buffer);

    merge(source + l, m - l, source + m, r - m, buffer);
    memcpy(source + l, buffer, sizeof(int) * n);
}

void mergeSort(int *a, size_t n) { // сортировка слиянием
    int *buffer = (int *) malloc(sizeof(int) * n);
    mergeSort_(a, 0, n, buffer);
    free(buffer);
}

void shellSort(int *a, size_t size) { // сортировка Шелла
    for (size_t step = size / 2; step > 0; step /= 2) {
        for (size_t i = step; i < size; i++) {
            int tmp = a[i];
            size_t j;
            for (j = i; j >= step; j -= step) {
                if (tmp < a[j - step]) {
                    a[j] = a[j - step];
                } else {
                    break;
                }
            }
            a[j] = tmp;
        }
    }
}

int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void radixSort_(int *a, int *n) {
    int bit = 8;
    int k = (32 + bit - 1) / bit;
    int M = 1 << bit;
    long long sz = n - a;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++) {
            c[j] = 0;
        }

        for (int *j = a; j < n; j++) {
            c[digit(*j, i, bit, M)]++;
        }

        for (int j = 1; j < M; j++) {
            c[j] += c[j - 1];
        }

        for (int *j = n - 1; j >= a; j--) {
            b[--c[digit(*j, i, bit, M)]] = *j;
        }

        int cur = 0;
        for (int *j = a; j < n; j++) {
            *j = b[cur++];
        }
    }

    free(b);
    free(c);
}

void radixSort(int *a, size_t n) {
    radixSort_(a, a + n);
}

void timeExperiment() {
    // описание функций сортировки
    SortFunc sorts[] = {
            {selectionSort, "selectionSort"}, // 3
            {insertionSort, "insertionSort"}, // 4
            {bubbleSort,    "bubbleSort"},    // 2
            {combSort,      "combSort"},      // 5
            {countSort,     "countSort"},
            {mergeSort,     "mergeSort"},
            {shellSort,     "shellSort"},     // 6
            {radixSort,     "radixSort"},     // 7
    };
    const unsigned FUNCS_N = ARRAY_SIZE (sorts);
    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,      "random"},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     "ordered"},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE (generatingFuncs);
    // запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time ",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}

int main() {
    timeExperiment();

    return 0;
}