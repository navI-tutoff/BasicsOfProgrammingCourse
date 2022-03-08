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

/// TASK 2
/// сократить количество пробелов между словами данного предложения до одного

void removeExtraSpaces(char *s) {
    char nonSpaceSymbol = findNonSpace(s);
    char *nowEl = s;
    char *nextEl = s + 1;
    while (*s != '\0') {
        if (*nowEl == ' ' && *nextEl == ' ') {
            *nowEl = nonSpaceSymbol;
            nowEl++;
            nextEl++;
            s++;
        } else {
            nowEl++;
            nextEl++;
            s++;
        }
    }
}
