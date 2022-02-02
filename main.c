#include <stdio.h>
#include <math.h>

int getCountDigits() {
    int n = getchar();
    if (n == '\n') {
        return 0;
    } else {
        return getCountDigits() + (n >= '0' && n <= '9');
    }
}

void searchFirstIndexMin_(const int *a, const int n, int *minIndex, const int
i) {
    if (i == n) {
        return;
    } else if (a[*minIndex] > a[i]) {
        *minIndex = i;
    }
    searchFirstIndexMin_(a, n, minIndex, i + 1);
}
int searchFirstIndexMin(const int *a, const int n) {
    int minIndex = 0;
    searchFirstIndexMin_(a, n, &minIndex, 1);

    return minIndex;
}

//void bubbleSort(int *a, const int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = n - 1; j > i; j--) {
//            if (a[j - 1] > a[j]) {
//                swap(&a[j - 1], &a[j]);
//            }
//        }
//    }
//}

int binarySearch(const int *a, const int n, const int x) {
    int left = -1;
    int right = n;

    while (right - left > 1) {
        int middle = left + (right - left) / 2;
        if (a[middle] >= x) {
            right = middle;
        } else if (a[middle] < x) {
            left = middle;
        }
    }

    return left;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};

    printf("%d\n", binarySearch(a, 5, 0));
    printf("%d\n", binarySearch(a, 5, 1));
    printf("%d\n", binarySearch(a, 5, 2));
    printf("%d\n", binarySearch(a, 5, 3));
    printf("%d\n", binarySearch(a, 5, 4));
    printf("%d\n", binarySearch(a, 5, 5));
    printf("%d\n", binarySearch(a, 5, 6));

}