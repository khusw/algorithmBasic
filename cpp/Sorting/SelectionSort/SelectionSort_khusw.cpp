#include <iostream>

using namespace std;

int main() {
    int i, j, min, index, temp;
    int arr[10] = {1, 5, 10, 2, 3, 7, 8, 9, 4, 6};
    for (i = 0; i < 10; i++) {
        min = 9999;
        for (j = i; j < 10; j++) {
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}
