#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++) {
        ms[i] = getMemMatrix(nRows, nCols);
    }
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        free(m.values[i]);
    }
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(ms[i]);
    }
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        swap(&m.values[i][j1], &m.values[i][j2]);
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *critArray = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        critArray[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 0; i < m.nRows; i++) {
        for (int j = i; i > 0 && critArray[j - 1] > critArray[j]; j--) {
            swap(&critArray[j - 1], &critArray[j]);
            swapRows(m, j - 1, j);
        }
    }

    free(critArray);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *critArray = (int *) malloc(sizeof(int) * m.nCols);
    int *addArray = (int *) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++) {
            addArray[j] = m.values[j][i];
        }
        critArray[i] = criteria(addArray, m.nRows);
    }

    for (int i = 0; i < m.nCols; i++) {
        for (int j = i; j > 0 && critArray[j - 1] > critArray[j]; j--) {
            swap(&critArray[j - 1], &critArray[j]);
            swapColumns(m, j - 1, j);
        }
    }

    free(critArray);
    free(addArray);
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows == m2.nRows && m1.nCols == m2.nCols) {
        bool isEqual = true;
        for (int i = 0; i < m1.nRows; i++) {
            for (int j = 0; j < m1.nCols; j++) {
                isEqual = (m1.values[i][j] == m2.values[i][j]);
                if (!isEqual) {
                    return false;
                }
            }
        }
    } else {
        return false;
    }

    return true; // а я то думал, почему у меня выводит "2"
}

bool isEMatrix(matrix m) {
    bool isEMatrix = false;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] == 1) {
                isEMatrix = j == i;
                if (!isEMatrix) {
                    return false;
                }
            }
        }
    }

    return isEMatrix;
}

bool isSymmetricMatrix(matrix m) {
    bool isSymmetric = true;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            isSymmetric = m.values[i][j] == m.values[j][i];
            if (!isSymmetric) {
                return false;
            }
        }
    }

    return isSymmetric;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = i + 1; j < m.nCols; j++) {
            swap(&m.values[i][j], &m.values[j][i]);
        }
    }
}

position getMinValuePos(matrix m) {
    position minValuePos;
    minValuePos.colIndex = 0;
    minValuePos.rowIndex = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            position curPos;
            curPos.rowIndex = i;
            curPos.colIndex = j;
            if (m.values[curPos.rowIndex][curPos.colIndex] < m.values[minValuePos.rowIndex][minValuePos.colIndex]) {
                minValuePos = curPos;
            }
        }
    }

    return minValuePos;
}

position getMaxValuePos(matrix m) {
    position maxValuePos;
    maxValuePos.colIndex = 0;
    maxValuePos.rowIndex = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            position curPos;
            curPos.rowIndex = i;
            curPos.colIndex = j;
            if (m.values[curPos.rowIndex][curPos.colIndex] > m.values[maxValuePos.rowIndex][maxValuePos.colIndex]) {
                maxValuePos = curPos;
            }
        }
    }

    return maxValuePos;
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            m.values[i][j] = a[k++];
        }
    }

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int L = 0;
    for (int k = 0; k < nMatrices; k++) {
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                ms[k].values[i][j] - values[L++];
            }
        }
    }

    return ms;
}