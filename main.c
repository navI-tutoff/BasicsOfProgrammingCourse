#include "libs\data_structures\matrix\matrix.h"

int main() {
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);

    outputMatrix(m);

    return 0;
}