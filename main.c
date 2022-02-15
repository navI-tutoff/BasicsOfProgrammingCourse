#include "libs\data_structures\matrix\matrix.h"



int main() {
    matrix m = getMemMatrix(4, 4);
    inputMatrix(m);

    printf("%d\n", isSymmetricMatrix(m));
}