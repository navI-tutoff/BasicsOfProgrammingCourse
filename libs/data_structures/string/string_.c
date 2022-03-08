#include "string_.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch) {
        begin++;
    }

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin)) {
        begin++;
    }

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin)) {
        begin++;
    }

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs && (*lhs == *rhs)) {
        return strcmp_(++lhs, ++rhs);
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSourse, const char *endSourse, char *beginDestination) {
    int capacity = endSourse - beginSourse;
    memcpy(beginDestination, beginSourse, capacity);

    return beginDestination + capacity;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination++ = *beginSource;
        }
        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination++ = *rbeginSource;
        }
        rbeginSource--;
    }

    return beginDestination;
}