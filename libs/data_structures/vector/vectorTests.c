#include "vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 28);

    assert(getVectorValue(&v, 0) == 28);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(3);
    pushBack(&v, 0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 4);

    assert(getVectorValue(&v, 3) == 4);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);

    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);

    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);

    assert(*atVector(&v, 0) == 1);
    assert(*atVector(&v, 2) == 3);
    assert(*atVector(&v, 4) == 5);

    deleteVector(&v);
}

void test_atVector_requestToLastElement_test1() {
    vector v = createVector(3);
    pushBack(&v, 4);
    pushBack(&v, 7);
    pushBack(&v, 28);

    assert(*atVector(&v, 2) == 28); // что-то я не понял, чем этот тест
    assert(*atVector(&v, 0) == 4);  // отличается от предыдущего

    deleteVector(&v);
}

void test_atVector_requestToLastElement_test2() {
    vector v = createVector(0);
    pushBack(&v, 14);

    assert(*atVector(&v, 0) == 14);

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    test_atVector_requestToLastElement_test1();
    test_atVector_requestToLastElement_test2();
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 4);

    assert(*back(&v) == 4);

    deleteVector(&v);
}

void test_back_severalElementsInVector() {
    vector v = createVector(4);
    pushBack(&v, 4);
    pushBack(&v, 5);
    pushBack(&v, 6);
    pushBack(&v, 8);

    assert(*back(&v) == 8);

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 4);

    assert(*front(&v) == 4);

    deleteVector(&v);
}

void test_front_severalElementsInVector() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 0);
    pushBack(&v, 4);

    assert(*front(&v) == 1);

    deleteVector(&v);
}

void test_vector_struct() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_back_severalElementsInVector();
    test_front_oneElementInVector();
    test_front_severalElementsInVector();
}

