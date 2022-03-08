#ifndef MYMAIN_STRING__H
#define MYMAIN_STRING__H

#include <stdint.h>

// возвращает количество символов в строке
size_t strlen_(const char *begin);

// возвращает указатель на первый элемент с кодом ch,
// расположенным на ленте памяти между адресами begin и end, не включая end.
// Если символ не найден, возвращается значение end
char* find(char *begin, char *end, int ch);

// возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// если символ не найден, возвращается адрес первого ноль-символа
char* findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти, начиная с адреса begin или на первый ноль-символ
char* findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin (последний символ
// строки, за которым следует ноль-символ),
// и заканчивая rend (адрес символа перед началом строки)
char* findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа,
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
// если символ не найден, возвращает адрес rend
char* findSpaceReverse(char *rbegin, const char *rend);

// возвращает отрицательное значение, если lhs располагается до rhs в лексикографическом порядке,
// значение 0, если lhs и rhs равны, иначе - положительное значение
int strcmp_(const char *lhs, const char *rhs);

// записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSourse
// до endSourse. Возвращает указатель на следующий свободный фрагмент памяти в destination
char* copy(const char *beginSourse, const char *endSourse, char *beginDestination);

// записывает по адресу beginDestination элементы из фрагмента памяти, начиная с beginSource
// и заканчивая endSource, удовлетворяющие функции-предикату f.
// возвращает указатель на следующий свободный для записи фрагмент в памяти
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента памяти, начиная с rbeginSource,
// заканчивая rendSource, удовлетворяющие функции-предикату f. Функция возвращает значение
// beginDestination по окончанию работы функции
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

#endif //MYMAIN_STRING__H
