#include <iostream>

using namespace std;

int a, b;
int answer;

int gcd(int a, int b) {
    int result = a % b;
    while (result != 0) {
        a = b;
        b = result;
        result = a % b;
    }
    return b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b;

    answer = gcd(a, b);

    cout << answer;

    return 0;
}