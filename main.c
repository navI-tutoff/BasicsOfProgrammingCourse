#include "libs\data_structures\matrix\matrix.h"

int main() {
    matrix *ms = getMemArrayOfMatrices(2, 2, 2);

    inputMatrices(ms, 2);
    outputMatrices(ms, 2);
}