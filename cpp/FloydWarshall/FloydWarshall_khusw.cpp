#include <stdio.h>
#define number 5
#define INF 1000000

int W[number][number] = {
    {0, 1, INF, 1, 5},
    {9, 0, 3, 2, INF},
    {INF, INF, 0, 4, INF},
    {INF, INF, 2, 0, 3},
    {3, INF, INF, INF, 0}};
int P[number][number];
int D[number][number];

void path(int x, int y) {
    if (P[x][y] != 0) {
        path(x, P[x][y]);
        printf("v%d", P[x][y]);
        path(P[x][y], y);
    }
}

void floydWarshall(int x, int y) {
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            D[i][j] = W[i][j];
        }
    }

    for (int k = 0; k < number; k++) {
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < number; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    P[i][j] = k + 1;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("%3d ", D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("%3d ", P[i][j]);
        }
        printf("\n");
    }

    path(x, y);
}

int main() {
    floydWarshall(5, 3);
    return 0;
}