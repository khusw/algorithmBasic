#include <stdio.h>
#define MIN(A, B) A < B ? A : B

int B[10][10];

int bin(int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MIN(i, k); j++) {
            if (j == 0 || j == i) {
                return B[i][j] = 1;
            } else {
                return B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
            }
        }
    }
}

int main() {
    int result = bin(5, 5);
    printf("%d", result);
    return 0;
}