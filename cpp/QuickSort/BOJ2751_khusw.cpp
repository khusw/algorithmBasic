/*
    BOJ 2751 수 정렬하기 2
    https://www.acmicpc.net/problem/2751
*/

#include <stdio.h>

void quickSort(int *data, int start, int end) {
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    if (start >= end) {
        return;
    }

    while (i <= j) {
        while (data[i] <= data[key]) {
            i++;
        }
        while (data[j] >= data[key] && j > start) {
            j--;
        }
        if (i > j) {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main() {
    int N;
    scanf("%d", &N);
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    delete[] arr;
    return 0;
}
