#include "libs/data_structures/ordered_array_set/ordered_array_set.h"

#define ARRAY_SIZE_A 4
#define ARRAY_SIZE_B 4
#define ARRAY_SIZE_C 4

#define ARRAY_SIZE_A2 7
#define ARRAY_SIZE_B2 5
#define ARRAY_SIZE_C2 5
#define ARRAY_SIZE_D2 5

int main() {
    ///     задания 4-5 для пункта 1
    printf("First Task \n \n");

    int a[ARRAY_SIZE_A] = {1, 2, 3, 8};
    ordered_array_set arraySetA = ordered_array_set_create_from_array(a, ARRAY_SIZE_A, ARRAY_SIZE_A);

    int b[ARRAY_SIZE_B] = {3, 5, 6, 7};
    ordered_array_set arraySetB = ordered_array_set_create_from_array(b, ARRAY_SIZE_B, ARRAY_SIZE_B);

    int c[ARRAY_SIZE_C] = {2, 3, 4, 7};
    ordered_array_set arraySetC = ordered_array_set_create_from_array(c, ARRAY_SIZE_C, ARRAY_SIZE_C);

    ordered_array_set firstStep = ordered_array_set_intersection(arraySetA, arraySetB);
    ordered_array_set secondStep = ordered_array_set_difference(arraySetA, arraySetC);
    ordered_array_set thirdStep = ordered_array_set_difference(arraySetB, arraySetC);
    ordered_array_set fourthStep = ordered_array_set_union(firstStep, secondStep);
    ordered_array_set fifthStep = ordered_array_set_union(fourthStep, thirdStep);

    printf("Result of firstStep - ");
    ordered_array_set_print(firstStep);
    printf("Result of secondStep - ");
    ordered_array_set_print(secondStep);
    printf("Result of thirdStep - ");
    ordered_array_set_print(thirdStep);
    printf("Result of fourthStep - ");
    ordered_array_set_print(fourthStep);
    printf("Result of fifthStep - ");
    ordered_array_set_print(fifthStep);

    printf("\n");

    ///     задания 4-5 для пункта 2
    printf("Second Task \n \n");

    int a2[ARRAY_SIZE_A2] = {1, 2, 3, 4, 5, 6, 7};
    ordered_array_set arraySetA2 = ordered_array_set_create_from_array(a2, ARRAY_SIZE_A2, ARRAY_SIZE_A2);

    int b2[ARRAY_SIZE_B2] = {2, 5, 6, 9, 10};
    ordered_array_set arraySetB2 = ordered_array_set_create_from_array(b2, ARRAY_SIZE_B2, ARRAY_SIZE_B2);

    int c2[ARRAY_SIZE_C2] = {4, 7, 8, 11, 12};
    ordered_array_set arraySetC2 = ordered_array_set_create_from_array(c2, ARRAY_SIZE_C2, ARRAY_SIZE_C2);

    int d2[ARRAY_SIZE_D2] = {2, 5, 6, 7, 4};
    ordered_array_set arraySetD2 = ordered_array_set_create_from_array(d2, ARRAY_SIZE_D2, ARRAY_SIZE_D2);

    ordered_array_set firstStep2 = ordered_array_set_intersection(arraySetA2, arraySetB2);
    ordered_array_set secondStep2 = ordered_array_set_intersection(arraySetA2, arraySetC2);
    ordered_array_set thirdStep2 = ordered_array_set_union(firstStep2, secondStep2);

    ordered_array_set_print(thirdStep2);

    if (ordered_array_set_isEqual(thirdStep2, arraySetD2)) {
        printf("Expected and gotten sets are equal \n");
    } else {
        printf("Expected and gotten sets are different \n");
    }

    return 0;
}