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

void stringStructureTests() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
}