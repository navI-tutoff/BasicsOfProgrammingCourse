#include "libs\data_structures\matrix\matrix.h"
#include <assert.h>

///                                                              The First Task

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

void tasks_tests() {
    test_task1();

}

int main() {
    tasks_tests();

    return 0;
}