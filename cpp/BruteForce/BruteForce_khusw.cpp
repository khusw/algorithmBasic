#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cout << arr[N - 1] + arr[N - 2];

    return 0;
}
