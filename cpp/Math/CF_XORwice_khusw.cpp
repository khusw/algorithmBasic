/*
    A. XORwice
    https://codeforces.com/contest/1421/problem/0
*/

#include <algorithm>
#include <iostream>

using namespace std;

int T;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        int result = a ^ b;
        cout << result << "\n";
    }

    return 0;
}