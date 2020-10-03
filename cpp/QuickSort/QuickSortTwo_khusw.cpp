
#include <iostream>

using namespace std;

void quickSort(int *data, int start, int end) {
    if (start >= end) {
        return;
    }

    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while (i <= j) {
        while (data[i] >= data[key]) {
            i++;
        }
        while (data[j] <= data[key] && j > start) {
            j--;
        }
        if (i > j) {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main() {
    int num = 10;
    int data[10] = {1, 5, 7, 8, 2, 3, 9, 10, 4, 6};
    quickSort(data, 0, num - 1);
    for (int i = 0; i < num; i++) {
        cout << data[i] << ' ';
    }
    return 0;
}