#include "matrix.h"
#include <assert.h>

void test_areTwoMatricesEqual_actuallyEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    5, 4, 6,
                    7, 0, 8,
                    1, -4, 1,
            },
            4, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    5, 4, 6,
                    7, 0, 8,
                    1, -4, 1,
            },
            4, 3
    );

    assert(areTwoMatricesEqual(m, m2));

    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_swapRows_swapTwoFirstsRows() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    5, 4, 6,
                    7, 0, 8,
                    1, -4, 1,
            },
            4, 3
    );
    swapRows(initialMatrix, 0, 1);

    matrix swapedRowsMatrix = createMatrixFromArray(
            (int[]) {
                    5, 4, 6,
                    1, 2, 3,
                    7, 0, 8,
                    1, -4, 1,
            },
            4, 3
    );

    assert(areTwoMatricesEqual(initialMatrix, swapedRowsMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(swapedRowsMatrix);
}

void test_swapColumns_swapTwoLatestColumns() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    5, 4, 6,
                    7, 0, 8,
                    1, -4, 1,
            },
            4, 3
    );
    swapColumns(initialMatrix, 1, 2);

    matrix swapedColumnsMatrix = createMatrixFromArray(
            (int[]) {
                    1, 3, 2,
                    5, 6, 4,
                    7, 8, 0,
                    1, 1, -4,
            },
            4, 3
    );

    assert(areTwoMatricesEqual(initialMatrix, swapedColumnsMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(swapedColumnsMatrix);
}

int getArraySum(int *a, const int n) {
    int sumArray = 0;
    for (int i = 0; i < n; i++) {
        sumArray += a[i];
    }
    return sumArray;
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 4, 3, 6,
                    7, 5, 5, 5, 8,
                    5, 3, 4, 3, 5,
            },
            3, 5
    );

    insertionSortRowsMatrixByRowCriteria(initialMatrix, getArraySum);

    matrix readyMatrix = createMatrixFromArray(
            (int[]) {
                    5, 3, 4, 3, 5,
                    3, 5, 4, 3, 6,
                    7, 5, 5, 5, 8,
            },
            3, 5
    );

    assert(areTwoMatricesEqual(initialMatrix, readyMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(readyMatrix);
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 4, 3, 6,
                    7, 5, 5, 5, 8,
                    5, 3, 4, 4, 5,
            },
            3, 5
    );

    insertionSortColsMatrixByColCriteria(initialMatrix, getArraySum);

    matrix readyMatrix = createMatrixFromArray(
            (int[]) {
                    3, 4, 6, 3, 6,
                    5, 5, 5, 7, 8,
                    4, 4, 3, 5, 5,
            },
            3, 5
    );

    assert(areTwoMatricesEqual(initialMatrix, readyMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(readyMatrix);
}

void test_isSquareMatrix_isActuallySquare() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 2, 1,
                    2, 1, 2,
            },
            3, 3
    );

    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_actuallyEMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            },
            3, 3
    );

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_actuallyIsSymmetric() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 2, 4,
                    3, 4, 3,
            },
            3, 3
    );

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_transposeSquareMatrix_actuallyIsTranspose() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 4,
                    5, 3,
            },
            2, 2
    );

    transposeSquareMatrix(m);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 5,
                    4, 3,
            },
            2, 2
    );

    assert(areTwoMatricesEqual(m, m2));

    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_getMinValuePos_secondIsMin() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 0,
                    5, 3,
            },
            2, 2
    );

    position expectedPos = getMinValuePos(m);
    position actuallyMinPos;
    actuallyMinPos.rowIndex = 0;
    actuallyMinPos.colIndex = 1;

    assert(expectedPos.rowIndex == 0);
    assert(expectedPos.colIndex == 1);

    freeMemMatrix(m);
}

void test_getMaxValuePos_firstIsMax() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    14, 0,
                    5, 3,
            },
            2, 2
    );

    position expectedPos = getMaxValuePos(m);
    position actuallyMaxPos;
    actuallyMaxPos.rowIndex = 0;
    actuallyMaxPos.colIndex = 0;

    assert(expectedPos.rowIndex == 0);
    assert(expectedPos.colIndex == 0);

    freeMemMatrix(m);
}

void test_matrix_struct() {
    test_areTwoMatricesEqual_actuallyEqual();
    test_swapRows_swapTwoFirstsRows();
    test_swapColumns_swapTwoLatestColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isSquareMatrix_isActuallySquare();
    test_isEMatrix_actuallyEMatrix();
    test_isSymmetricMatrix_actuallyIsSymmetric();
    test_transposeSquareMatrix_actuallyIsTranspose();
    test_getMinValuePos_secondIsMin();
    test_getMaxValuePos_firstIsMax();
}