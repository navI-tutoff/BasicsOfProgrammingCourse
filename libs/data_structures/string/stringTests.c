#include "string_.h"
#include <assert.h>

void test_strlen__lengthIsZero() {
    char initialString[] = "";
    char realLength = 0;

    assert(strlen_(initialString) == realLength);
}

void test_strlen__lengthIsFive() {
    char initialString[] = "abcde";
    char realLength = 5;

    assert(strlen_(initialString) == realLength);
}

void test_strlen_() {
    test_strlen__lengthIsZero();
    test_strlen__lengthIsFive();
}

//void test_find

void stringStructureTests() {
    test_strlen_();
}