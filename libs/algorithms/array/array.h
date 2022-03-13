#ifndef MYMAIN_ARRAY_H
#define MYMAIN_ARRAY_H

#include <stdio.h>
#include <stdbool.h>

// ввод массива a размера n
void inputArray(int *a, size_t n);

// выводит значения элементов массива a размера n
void outputArray(const int *a, size_t n);

// возвращает индекс первого элемента массива a размера n со
// значением x, если элемент со значением x найден в массиве a,
// в противном случае возвращает -1
int linearSearch(const int *a, const int n, int x);

// возвращает индекс первого элемента, удовлятворяющего условию
// предикату f, если элемент со значением x
// найден в массиве a размера n, иначе возвращает -1
int linearSearchIf(const int *a, const int n, bool (*f)(const int));

// возвращает индекс последнего элемента, удовлятворяющего
// условию предикату f, если элемент со значением x
// найден в массиве a размера n, иначе возвращает -1
int rLinearSearchIf(const int *a, const int n, bool (*f)(const int));

// возвращает количество элементов, удовлятворяющих условию предикату f
int countIf(const int *a, const int n, bool (*f)(const int));

// меняет порядок элементов массива a размера n на обратный
void reverseArray(int *a, const int n);

// возвращает значение 1, если массив a размера n является палиндромом, иначе возвращает 0
int isPalindromeArray(const int *a, const int n);

// упорядочивает элементы массива a размера n по неубыванию
void selectionSort(int *a, const int n);

// удаляет из массива a размера n значения, удовлетворяющие функции-предикату f
void deleteIf(int *a, int *n, bool (*f)(const int));

// вставляет значение x на позицию pos в массиве a размера n
// увеличивает количество элементов n на единицу
void insertX(int *a, int *n, const int x, const int pos);

// добавляет значение x в конец массива a размера n
void append(int *a, int *n, const int x);

// добавляет значение x в конец массива a размера size
void append_size_t(int *array, size_t *size, const int value);

// удаляет элемент на позиции pos из массива a размера n
// уменьшает количество элементов n на единицу
void safeDelete(int *a, int *n, const int pos);

// удаляет элемент на позиции pos из массива a размера n
// уменьшает количество элементов n на единицу
void unSafeDelete(int *a, int *n, const int pos);

void copyArray(const int *b, const int *a, size_t size);

int binarySearch(const int *a, int n, int x);

int binarySearchLessOrEqual(const int *a, const int n, const int x);

void insert(int *const a, size_t *const n, const size_t pos, const int value);


#endif //MYMAIN_ARRAY_H
