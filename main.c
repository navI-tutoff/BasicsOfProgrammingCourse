#include "libs\data_structures\matrix\matrix.h"
//#include "libs\data_structures\matrix\matrixTests.c"
#include <assert.h>

///                                                                                  First Task

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

///                                                                                 Second Task

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
    selectionSortRowsMatrixByRowCriteria(m, getMax);
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

///                                                                                  Third Task

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }

    return min;
}

void task3(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

void test_task3_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3,
            },
            3, 6
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4,
            },
            3, 6
    );

    task3(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task3_2() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
            },
            3, 4
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
            },
            3, 4
    );

    task3(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task3() {
    test_task3_1();
    test_task3_2();
}

///                                                                                 Fourth Task

void task4(matrix *m) {
    if (isSquareMatrix(*m)) {
        *m = mulMatrices(*m, *m);
    }
}

void test_task4_isSquareMatrix() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    7, 10,
                    15, 22,
            },
            2, 2
    );

    task4(&initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task4_aintSquareMatrix() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    3, 4, 6,
            },
            2, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    3, 4, 6,
            },
            2, 3
    );

    task4(&initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task4() {
    test_task4_isSquareMatrix();
    test_task4_aintSquareMatrix();
}

///                                                                                  Fifth Task

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                return 0;
            }
        }
    }
    return 1;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum;
}

void task5(matrix m) {
    long long rowsSum[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        rowsSum[i] = getSum(m.values[i], m.nCols);
    }

    if (isUnique(rowsSum, m.nRows)) {
        transposeSquareMatrix(m);
    }
}

void test_task5_equalSum() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 0,
            },
            2, 2
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 0,
            },
            2, 2
    );

    task5(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task5_differentSum() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 1,
            },
            2, 2
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 3,
                    2, 1,
            },
            2, 2
    );

    task5(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task5() {
    test_task5_equalSum();
    test_task5_differentSum();
}

///                                                                                  Sixth Task

bool task6(matrix m1, matrix m2) {
    matrix multiplication = mulMatrices(m1, m2);
    bool isInverse = isEMatrix(multiplication);

    return isInverse;
}

void test_task6_isInverse() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24,
            },
            3, 3
    );

    task6(initialMatrix, expectedMatrix);

    assert(task6(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task6_isntInverse() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    4, 1, 1,
                    -38, 71, -34,
                    27, -29, 14,
            },
            3, 3
    );

    task6(initialMatrix, expectedMatrix);

    assert(!task6(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task6() {
    test_task6_isInverse();
    test_task6_isntInverse();
}

///                                                                                Seventh Task

int max2(int a, int b) {
    return a > b ? a : b;
}

#include <limits.h>

long long task7(matrix m) {
    int arrSize = m.nRows + m.nCols - 1;
    int elemOfPseudoDiagonal[m.nRows + m.nCols - 1];

    for (int i = 0; i < arrSize; i++) {
        elemOfPseudoDiagonal[i] = INT_MIN;
    }

    elemOfPseudoDiagonal[m.nRows - 1] = 0; /// middle

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (i != j) {
                int k = j - i + m.nRows - 1;
                elemOfPseudoDiagonal[k] = max2(elemOfPseudoDiagonal[k], m.values[i][j]);
            }
        }
    }

    return getSum(elemOfPseudoDiagonal, arrSize);
}

void test_task7_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2,
            },
            3, 4
    );

    assert(task7(initialMatrix) == 20);

    freeMemMatrix(initialMatrix);
}

void test_task7() {
    test_task7_1();
}

///                                                                                 Eighth Task

int min2(int a, int b) {
    return a < b ? a : b;
}

int task8(matrix m) {
    position pos = getMaxValuePos(m);
    int elem = m.values[pos.rowIndex][pos.colIndex];

    int right = pos.colIndex;
    int left = pos.colIndex;
    for (int i = pos.rowIndex - 1; i >= 0; i--) {
        left = left > 0 ? left - 1 : left;
        right = right < m.nCols ? right + 1 : right;

        elem = min2(getMin(&m.values[i][left], right - left), elem);
    }

    return elem;
}

void test_task8_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2,
            },
            3, 4
    );

    assert(task8(initialMatrix) == 5);

    freeMemMatrix(initialMatrix);
}

void test_task8_2() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1,
            },
            3, 4
    );

    assert(task8(initialMatrix) == 6);

    freeMemMatrix(initialMatrix);
}

void test_task8() {
    test_task8_1();
    test_task8_2();
}

///                                                                                  Ninth Task

#include <math.h>
#include <stdlib.h>

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++) {
        distance += (float) (a[i] * a[i]);
    }

    return sqrtf(distance);
}

void swapF(float *a, float *b) {
    float t = *a;
    *a = *b;
    *b = t;
}

void selectionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *critArray = (float *) malloc(sizeof(float) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        critArray[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 0; i < m.nRows - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < m.nRows; j++) {
            if (critArray[j] < critArray[minPos]) {
                minPos = j;
            }
        }
        swapF(&critArray[i], &critArray[minPos]);
        swapRows(m, i, minPos);
    }

    free(critArray);
}

void task9(matrix m) {
    selectionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void test_task9_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    2, 4, 3, // 5.3
                    6, 3, 4, // 7.8
                    5, 2, 3, // 6,1
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    2, 4, 3,
                    5, 2, 3,
                    6, 3, 4,
            },
            3, 3
    );

    task9(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task9() {
    test_task9_1();
}

///                                                                                  Tenth Task

int compare_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const int *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2) {
        return -1;
    }
    if (arg1 > arg2) {
        return 1;
    }

    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), compare_long_long);

    int uniqueAccount = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            uniqueAccount++;
        }
    }

    return uniqueAccount;
}

int task10(matrix m) {
    long long rowSum[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        rowSum[i] = getSum(m.values[i], m.nCols);
    }

    return countNUnique(rowSum, m.nRows);
}

void test_task10_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0,
            },
            6, 2
    );

    assert(task10(initialMatrix) == 3);

    freeMemMatrix(initialMatrix);
}

void test_task10() {
    test_task10_1();
}

///                                                                              Eleventh  Task

int task11(matrix m) {
    int specialAccount = 0;
    for (int j = 0; j < m.nCols; j++) {
        int specialEl = m.values[0][j];
        int columnSum = 0;
        for (int i = 1; i < m.nRows; i++) {
            if (m.values[i][j] > specialEl) {
                columnSum += specialEl;
                specialEl = m.values[i][j];
            } else {
                columnSum += m.values[i][j];
            }
        }
        if (specialEl > columnSum) {
            specialAccount += 1;
        }
    }

    return specialAccount;
}

void test_task11_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2,
            },
            3, 4
    );

    assert(task11(initialMatrix) == 2);

    freeMemMatrix(initialMatrix);
}

void test_task11() {
    test_task11_1();
}

///                                                                                Twelfth Task

position getLeftMin(matrix m) {
    int min = m.values[0][0];
    position minPos = {0, 0};

    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                minPos.colIndex = j;
                minPos.rowIndex = i;
            }
        }
    }

    return minPos;
}

#include <memory.h>

void task12(matrix m) {
    position min = getLeftMin(m);

    int column[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        column[i] = m.values[i][min.colIndex];
    }

    memcpy(m.values[m.nRows - 2], column, sizeof(int) * m.nCols);
}

void test_task12_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1,
            },
            3, 3
    );


    task12(initialMatrix);

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1,
            },
            3, 3
    );

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task12() {
    test_task12_1();
}

void tasks_tests() {
    test_task1();
    test_task2();
    test_task3();
    test_task4();
    test_task5();
    test_task6();
    test_task7();
    test_task8();
    test_task9();
    test_task10();
    test_task11();
    test_task12();
}

int main() {
    tasks_tests();

    return 0;
}