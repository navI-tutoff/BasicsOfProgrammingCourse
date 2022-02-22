#include "libs\data_structures\matrix\matrix.h"
#include <assert.h>

///                                                               First Task

void task1(matrix m) {
    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);
}

void test_task1_minAndMaxInTheDifferentRows() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 8,
                    5, 4, 6,
                    7, 0, 3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    7, 0, 3,
                    5, 4, 6,
                    1, 2, 8,
            },
            3, 3
    );

    task1(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task1_minAndMaxInTheSameRows() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 0, 8,
                    5, 4, 6,
                    7, 2, 3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 0, 8,
                    5, 4, 6,
                    7, 2, 3,
            },
            3, 3
    );

    task1(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task1() {
    test_task1_minAndMaxInTheDifferentRows();
    test_task1_minAndMaxInTheSameRows();
}

///                                                              Second Task

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    return max;
}

void task2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_task2_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1,
            },
            3, 3
    );

    task2(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task2_2() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 4, 0,
                    9, 8, 7,
                    3, 2, 2,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    3, 2, 2,
                    1, 4, 0,
                    9, 8, 7,
            },
            3, 3
    );

    task2(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task2() {
    test_task2_1();
    test_task2_2();
}

///                                                                                            Third Task

//



void tasks_tests() {
    test_task1();
    test_task2();
}

int main() {
    tasks_tests();

    return 0;
}