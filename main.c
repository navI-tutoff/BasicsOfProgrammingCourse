#include "libs\data_structures\matrix\matrix.h"



int main() {
    matrix m = getMemMatrix(2, 2);
    inputMatrix(m);

    position max = getMaxValuePos(m);
    position min = getMinValuePos(m);

    printf("MAX: %d %d\n", max.rowIndex, max.colIndex);
    printf("MIN: %d %d", min.rowIndex, min.colIndex);
}