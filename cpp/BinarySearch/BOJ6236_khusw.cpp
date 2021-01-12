#include <algorithm>
#include <iostream>

#define MAX 100001
#define INF 987654321

using namespace std;

int n, m, sum;
int answer = INF;
int arr[MAX];

bool check(int mid) {
    int cnt = 1, temp = mid;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > mid) return false;

        if (temp < arr[i]) {
            temp = mid;
            cnt++;
        }
        temp -= arr[i];
    }
    return cnt <= m;
}

void search() {
    int left = 1, right = sum;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            right = mid - 1;
            answer = min(answer, mid);
        } else
            left = mid + 1;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    search();
    cout << answer;

    return 0;
}