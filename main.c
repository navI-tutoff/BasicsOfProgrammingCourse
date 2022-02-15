#include "libs\data_structures\matrix\matrix.h"



int main() {
    matrix m = getMemMatrix(2, 2);
    inputMatrix(m);

    swapColumns(m, 0, 1);

    outputMatrix(m);
}