/*
    BOJ 1431 조금 더 복잡한 문자열 정렬
    https://www.acmicpc.net/problem/1431
*/

#include <algorithm>
#include <iostream>

using namespace std;

int n;
string a[20000];

int getSum(string a) {
    int length = a.length(), sum = 0;
    for (int i = 0; i < length; i++) {
        if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
            sum += a[i] - '0';
        }
    }
    return sum;
}

bool compare(string a, string b) {
    if (a.length() < b.length()) {
        return 1;
    } else if (a.length() > b.length()) {
        return 0;
    } else {
        int aSum = getSum(a);
        int bSum = getSum(b);
        if (aSum != bSum) {
            return aSum < bSum;
        } else {
            return a < b;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
}
