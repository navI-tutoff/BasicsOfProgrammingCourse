#include "tasks.h"
#include <assert.h>

#define MAX_SIZE_STRING 1000

///                 TASK 1

void test_removeNonLetters_aintSpace() {
    char s[] = "Rake";

    removeNonLetters(s);
    char expected[MAX_SIZE_STRING] = "Rake";

    assert(strcmp_(expected, s) == 0);
}

void test_removeNonLetters_withSpace() {
    char s[] = "\t Ra k \n e";

    removeNonLetters(s);
    char expected[MAX_SIZE_STRING] = "Rake";

    assert(strcmp_(expected, s) == 0);
}

void test_removeNonLetters() {
    test_removeNonLetters_aintSpace();
    test_removeNonLetters_withSpace();
}

///                 TASK 2

void test_removeExtraSpaces_thereAreSpaces() {
    char s[] = "Hello,  World!    Dude.";

    removeExtraSpaces(s);
    char expected[MAX_SIZE_STRING] = "Hello, World! Dude.";

    assert(strcmp_(s, expected) == 0);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_thereAreSpaces();
}

void tasksTests() {
    test_removeNonLetters();
    test_removeExtraSpaces();
}
