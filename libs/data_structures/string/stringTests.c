#include "string_.h"
#include <assert.h>

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

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

void test_find_aintElement() {
    char *s = "abcde";

    assert(*find(s, "\0", 'f') == '\0');
}

void test_find_thereIsElement() {
    char s[] = "abcde";

    assert(*find(s, "\0", 'c') == 'c');
}

void test_find() {
    test_find_aintElement();
    test_find_thereIsElement();
}

void test_findNonSpace_emptyString() {
    char s[] = "";

    assert(*findNonSpace(s) == '\0');
}

void test_findNonSpace_aintSpace() {
    char s[] = "Rake";

    assert(*findNonSpace(s) == 'R');
}

void test_findNonSpace_withSpace() {
    char s[] = "\n \t     Ra ke";

    assert(*findNonSpace(s) == 'R');
}

void test_findNonSpace() {
    test_findNonSpace_emptyString();
    test_findNonSpace_aintSpace();
    test_findNonSpace_withSpace();
}

void test_findSpace_emptyString() {
    char s[] = "";

    assert(*findSpace(s) == '\0');
}

void test_findSpace_thereIsSpace() {
    char s[] = "Hello, World!";

    assert(*findSpace(s) == s[6]);
}

void test_findSpace_aintSpace() {
    char s[] = "Rake";

    assert(*findSpace(s) == '\0');
}

void test_findSpace() {
    test_findSpace_emptyString();
    test_findSpace_thereIsSpace();
    test_findSpace_aintSpace();
}

void test_findNonSpaceReverse_emptyString() {
    char *s = "";

    assert(*findNonSpaceReverse(&s[1], s) == '\0');
}

void test_findNonSpaceReverse_aintSpace() {
    char s[] = "Rake";

    assert(*findNonSpaceReverse(&s[3], s) == 'e');
}

void test_findNonSpaceReverse_stringWithSpaceAtReverseBeginning() {
    char s[] = "Hello, World! \t \n";

    assert(*findNonSpaceReverse(&s[16], s) == '!');
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_emptyString();
    test_findNonSpaceReverse_aintSpace();
    test_findNonSpaceReverse_stringWithSpaceAtReverseBeginning();
}

void test_findSpaceReverse_emptyString() {
    char *s = "";

    assert(*findSpaceReverse(&s[1], s) == '\0');
}

void test_findSpaceReverse_aintSpace() {
    char s[] = "Rake";

    assert(*findSpaceReverse(&s[3], s) == 'R');
}

void test_findSpaceReverse() {
    test_findSpaceReverse_emptyString();
    test_findSpaceReverse_aintSpace();
}

void test_strcmp_stringsEqual() {
    char s[] = "Rake";
    char s2[] = "Rake";

    assert(strcmp_(s, s2) == 0);
}

void test_strcmp_differentStrings() {
    char s[] = "Rake";
    char s2[] = "Rakf";

    assert(strcmp_(s, s2) == 'e' - 'f');
}

void test_strcmp_() {
    test_strcmp_stringsEqual();
    test_strcmp_differentStrings();
}

void test_copy_copyWholeString() {
    char s[] = "Rake";
    char s2[5] = "";

    char *destination = copy(s, s + 4, s2);

    assert(strcmp_(s, s2) == 0 && destination == &s2[strlen_(s2)]);
}

void test_copy_copyPartOfString() {
    char s[] = "Rake";
    char s2[5] = "  te";

    char *destination = copy(s, s + 2, s2);
    char expected[5] = "Rate";

    assert(strcmp_(expected, s2) == 0 && destination == &s2[strlen_(s2) - 2]);
}

void test_copy() {
    test_copy_copyWholeString();
    test_copy_copyPartOfString();
}

void test_copyIf_isDigit() {
    char s[] = "Rake890";
    char s2[4] = "";

    char *destination = copyIf(s, s + 7, s2, isdigit);
    char expected[4] = "890";

    assert(strcmp_(expected, s2) == 0 && destination == &s2[strlen_(s2)]);
}

void test_copyIf() {
    test_copyIf_isDigit();
}

void test_copyIfReverse_digit() {
    char s[] = "Rake890";
    char s2[4] = "";

    char *destination = copyIfReverse(s + 7, s, s2, isdigit);
    char expected[4] = "098";

    assert(strcmp_(expected, s2) == 0 && destination == &s2[strlen_(s2)]);
}

void test_copyIfReverse() {
    test_copyIfReverse_digit();
}

void stringLibraryTests() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp_();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}