#ifndef MYMAIN_VECTOR_H
#define MYMAIN_VECTOR_H

#include <stdio.h>
#include <stdbool.h>

typedef struct vector {
    int *data;       // указатель на элементы вектора
    size_t size;     // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет количество памяти, выделенное под хранение элементов вектора
void reverse(vector *v, size_t newCapacity);

// удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору
void deleteVector(vector *v);

// возвращает 1, если вектор является пустым
bool isEmpty(vector *v);

// возвращает 1, если вектор является полным
bool isFull(vector *v);

// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора v
// если вектор заполнен, увеличивает количество выделенной ему памяти в 2 раза
void pushBack(vector *v, int x);

// удаляет последний элемент из вектора
// если вектор пуст, выдаёт сообщение в поток ошибок
void popBack(vector *v);


#endif //MYMAIN_VECTOR_H
