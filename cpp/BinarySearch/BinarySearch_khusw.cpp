#include <stdio.h>

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    int low, high, mid, location, x;
    scanf("%d", &x);
    low = 0;
    high = 9;
    location = 0;

    while (low <= high && location == 0) {
        mid = (low + high) / 2;
        if (x == arr[mid])
            location = mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("x 의 위치는 ");
    printf("%d", location);
    return 0;
}