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
    int data[10] = {100, 50, 60, 24, 37, 49, 61, 51, 99, 77};

    quickSort(data, 0, num - 1);
    for (int i = 0; i < num; i++) {
        cout << data[i] << ' ';
    }
}
