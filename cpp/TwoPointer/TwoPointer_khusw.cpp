#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int start, end, count, sum = 0;
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    while (start < N) {
        if (sum >= M) {
            sum = sum - array[start++];
        } else if (end == N) {
            break;
        } else {
            sum = sum + array[end++];
        }

        if (sum == M) {
            count++;
        }
    }

    cout << count;
}