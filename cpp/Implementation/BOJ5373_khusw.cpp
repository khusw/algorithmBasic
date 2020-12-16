/*
    BOJ 5373 큐빙
    https://www.acmicpc.net/problem/5373
*/

#include <cstdio>

using namespace std;

enum PLANE { U,
             D,
             F,
             B,
             L,
             R,
             SIZE };
int cube[SIZE][3][3];
char arr[55];
const char init[7] = "wyrogb";
char temp[3][3];

int rotation[6][12] = {
    {36, 37, 38, 18, 19, 20, 45, 46, 47, 27, 28, 29},
    {33, 34, 35, 51, 52, 53, 24, 25, 26, 42, 43, 44},
    {6, 7, 8, 44, 41, 38, 11, 10, 9, 45, 48, 51},
    {2, 1, 0, 53, 50, 47, 15, 16, 17, 36, 39, 42},
    {0, 3, 6, 35, 32, 29, 9, 12, 15, 18, 21, 24},
    {8, 5, 2, 26, 23, 20, 17, 14, 11, 27, 30, 33},
};

void print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%c", arr[cube[U][i][j]]);
        }
        printf("\n");
    }
}

void turn_cube(PLANE plane, int clock_wise) {
    char q[12];

    while (clock_wise--) {
        for (int i = 0; i < 12; ++i) q[i] = arr[rotation[plane][i]];
        for (int i = 0; i < 12; ++i) arr[rotation[plane][i]] = q[(i + 3) % 12];

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp[j][2 - i] = arr[cube[plane][i][j]];

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                arr[cube[plane][i][j]] = temp[i][j];
    }
}

int conv[256];

int main() {
    conv['-'] = 3;
    conv['+'] = 1;
    conv['U'] = U;
    conv['D'] = D;
    conv['F'] = F;
    conv['B'] = B;
    conv['L'] = L;
    conv['R'] = R;

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                cube[i][j][k] = i * 9 + j * 3 + k;

    int n, m;
    char command[3];
    scanf("%d", &n);

    while (n--) {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 9; ++j)
                arr[i * 9 + j] = init[i];

        scanf("%d", &m);

        while (m--) {
            scanf("%s", command);
            int plane = conv[command[0]], clock_wise = conv[command[1]];
            turn_cube((PLANE)plane, clock_wise);
        }

        print();
    }

    return 0;
}