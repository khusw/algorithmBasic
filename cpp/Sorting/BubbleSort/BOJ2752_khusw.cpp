/*
    BOJ 2752 세 수 정렬
*/

#include <stdio.h>

int main() {
    int min, index, temp;
    int arr[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 3; i++) {
        min = 1000001;
        for (int j = i; j < 3; j++) {
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}