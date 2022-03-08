#include "tasks.h"

/// TASK 1
/// удалить из строки все пробельные символы

char *getEndOfString(char *s) {
    return &s[strlen_(s)];
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

