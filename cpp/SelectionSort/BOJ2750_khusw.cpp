#include <iostream>

using namespace std;

int main() {
    int N, temp;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr[i] = temp;
    }

    int tmp, min, index;
    for (int x = 0; x < N; x++) {
        min = 9999;
        for (int y = x; y < N; y++) {
            if (min > arr[y]) {
                min = arr[y];
                index = y;
            }
        }
        tmp = arr[x];
        arr[x] = arr[index];
        arr[index] = tmp;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
    delete[] arr;
}