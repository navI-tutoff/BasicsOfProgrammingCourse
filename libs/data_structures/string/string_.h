#ifndef MYMAIN_STRING__H
#define MYMAIN_STRING__H

#include <stdint.h>

// возвращает количество символов в строке
size_t strlen_(const char *begin);

// возвращает указатель на первый элемент с кодом ch,
// расположенным на ленте памяти между адресами begin и end, не включая end.
// Если символ не найден, возвращается значение end
char* find(char *begin, char *end, int ch);

#endif //MYMAIN_STRING__H
