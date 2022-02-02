#include "unordered_array_set.h"

int compare_ints1(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

static void unordered_array_set_shrinkToFit(unordered_array_set *arr) {
    if (arr->size != arr->capacity) {
        arr->data = (int *) realloc(arr->data, arr->size * sizeof(int));

        arr->capacity = arr->size;
    }
}

unordered_array_set unordered_array_set_create(const size_t capacity) {
    return (unordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity,
    };
}

unordered_array_set unordered_array_set_create_from_array(const int *arr, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);

    for (register size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, arr[i]);

    unordered_array_set_shrinkToFit(&set);

    return set;
}

size_t linSearch(const int arr[], const size_t n, const int value) {
    for (int i = 0; i < n; i++)
        if (arr[i] == value)
            return i;

    return n;
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unordered_array_set_in(unordered_array_set *set, int value) {
    size_t index = linSearch(set->data, set->size, value);

    return index;
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return false;
    else {

        qsort(set1.data, set1.size, sizeof(int), compare_ints1);
        qsort(set2.data, set2.size, sizeof(int), compare_ints1);

        return !memcmp(set1.data, set2.data, sizeof(int) * set1.size);
    }
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

void append(int arr[], size_t *size, const int value) {
    arr[*size] = value;
    (*size)++;
}

// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value) {
    set->data = (int *) realloc(set->data, (set->size + 1) * sizeof(int));
    append(set->data, &set->size, value);
    unordered_array_set_shrinkToFit(set);
}

void delete(int arr[], size_t *size, const size_t index) {
    (*size)--;
    arr[index] = arr[*size];
}

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t index = unordered_array_set_in(set, value);

    if (index != set->size)
        delete(set->data, &set->size, index);
    unordered_array_set_shrinkToFit(set);
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set unionSet = unordered_array_set_create(set1.size + set2.size);

    for (register size_t i = 0; i < set1.size; i++)
        append(unionSet.data, &unionSet.size, set1.data[i]);

    for (register size_t i = 0; i < set2.size; i++)
        unordered_array_set_insert(&unionSet, set2.data[i]);

    unordered_array_set_shrinkToFit(&unionSet);

    return unionSet;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size);

    for (register size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size)
            append(set.data, &set.size, set2.data[i]);

    unordered_array_set_shrinkToFit(&set);

    return set;
}

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    unordered_array_set set3 = unordered_array_set_create(capacity);

    for (int i = 0; i < set1.size; i++) {
        unordered_array_set_insert(&set3, set1.data[i]);
    }
    for (int i = 0; i < set2.size; i++) {
        if (unordered_array_set_in(&set3, set2.data[i]) != set2.size)
            unordered_array_set_deleteElement(&set3, set2.data[i]);
    }
    unordered_array_set_shrinkToFit(&set3);
    return set3;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set diffSet1 = unordered_array_set_difference(set1, set2);
    unordered_array_set diffSet2 = unordered_array_set_difference(set2, set1);
    unordered_array_set symmetricDifference = unordered_array_set_union(diffSet1, diffSet2);

    unordered_array_set_delete(diffSet1);
    unordered_array_set_delete(diffSet2);

    return symmetricDifference;
}


// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    return unordered_array_set_union(set, universumSet);
}

// вывод множества set
void unordered_array_set_print(unordered_array_set set) {
    printf("{");

    for (register size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
    }

    if (set.size == 0) {
        printf("}");
    } else {
        printf("\b\b}\n");
    }
}

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}

////                                                                                         Start Tests

void test_unordered_array_set_in1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {7, 1, 4, 5, 8}, 5);
    int value = 1;
    size_t resSet = unordered_array_set_in(&set, value);
    size_t needRes = 1;
    assert(needRes == resSet);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {-3, -4, -2, -5}, 4);
    int value = -5;
    size_t resSet = unordered_array_set_in(&set, value);
    size_t needRes = 3;
    assert(needRes == resSet);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in3() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {-1, -3, -2, -5, 3, 1, 22, 13}, 8);
    int value = -1;
    size_t resSet = unordered_array_set_in(&set, value);
    size_t needRes = 0;
    assert(needRes == resSet);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
    test_unordered_array_set_in3();
}

void test_unordered_array_set_insert1() {
    unordered_array_set resSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
    int value = 5;
    unordered_array_set_insert(&resSet, value);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(unordered_array_set_isEqual(needRes, resSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_insert2() {
    unordered_array_set resSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4}, 4);
    int value = 0;
    unordered_array_set_insert(&resSet, value);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4, 0}, 5);
    assert(unordered_array_set_isEqual(needRes, resSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_insert3() {
    unordered_array_set resSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4}, 4);
    int value = -4;
    unordered_array_set_insert(&resSet, value);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4, -4}, 5);
    assert(unordered_array_set_isEqual(needRes, resSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
    test_unordered_array_set_insert3();
}

void test_unordered_array_set_deleteElement1() {
    unordered_array_set resSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4}, 4);
    int value = 7;
    unordered_array_set_deleteElement(&resSet, value);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);
    assert(unordered_array_set_isEqual(needRes, resSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_deleteElement2() {
    unordered_array_set resSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4}, 4);
    int value = 2;
    unordered_array_set_deleteElement(&resSet, value);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 7, 4}, 3);
    assert(unordered_array_set_isEqual(needRes, resSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_deleteElement3() {
    unordered_array_set resSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4}, 4);
    int value = 4;
    unordered_array_set_deleteElement(&resSet, value);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 7}, 3);
    assert(unordered_array_set_isEqual(needRes, resSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_deleteElement() {
    test_unordered_array_set_deleteElement1();
    test_unordered_array_set_deleteElement2();
    test_unordered_array_set_deleteElement3();
}

void test_unordered_array_set_union1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
            {1, 2, 7, 4}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
            {1, 2, 3}, 3);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4, 1, 2, 3}, 7);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
            {1, 2, 7, 4}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
            {8}, 1);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4, 8}, 5);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_union3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 7, 4}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 7}, 3);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 7, 4, 1, 2, 7}, 7);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
    test_unordered_array_set_union3();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 7, 4}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {0, 3, 5}, 3);
    unordered_array_set resSet = unordered_array_set_intersection(set1,
                                                                  set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {0}, 0);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 7, 4}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 77, 23}, 3);
    unordered_array_set resSet = unordered_array_set_intersection(set1,
                                                                  set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1}, 1);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_intersection3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 7, 4}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2}, 4);
    unordered_array_set resSet = unordered_array_set_intersection(set1,
                                                                  set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
    test_unordered_array_set_intersection3();
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 7, 4}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 3, 7, 2}, 4);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {4}, 1);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {42, 1, 7, 5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {0, 1, 7}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {42, 5}, 2);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_difference3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 3, 4, 5, 6}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {2, 3, 4, 7, 5}, 5);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 6}, 2);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
    test_unordered_array_set_difference3();
}

void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {2, 3, 4}, 3);
    unordered_array_set resSet =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 4}, 2);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {}, 0);
    unordered_array_set resSet =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_symmetricDifference3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {3, 2, 1}, 3);
    unordered_array_set resSet =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {0}, 0);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();
    test_unordered_array_set_symmetricDifference3();
}

void test_unordered_array_set_complement1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {1, 2, 3}, 3);
    unordered_array_set setUniverse =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set,
                                                                         setUniverse);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {4, 5}, 2);
    assert(unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set);
    unordered_array_set_delete(setUniverse);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_complement2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {1, 2, 3, 4, 5}, 5);
    unordered_array_set setUniverse =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set,
                                                                         setUniverse);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set);
    unordered_array_set_delete(setUniverse);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_complement3() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {0}, 0);
    unordered_array_set setUniverse =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set,
                                                                         setUniverse);
    unordered_array_set needRes =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert (unordered_array_set_isEqual(resSet, needRes));
    unordered_array_set_delete(set);
    unordered_array_set_delete(setUniverse);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}

void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
    test_unordered_array_set_complement3();
}

void test_unordered_array_set() {
    test_unordered_array_set_in();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_insert();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
}