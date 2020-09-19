/*
    BOJ 10448 유레카 이론
    https://www.acmicpc.net/problem/10448
*/

#include <iostream>

using namespace std;

int T;
int triangle_num[45];

void make_triangle_num() {
    for (int i = 0; i < 45; i++) {
        triangle_num[i] = (i * (i + 1)) / 2;
    }
}

bool check_num(int num) {
    for (int i = 1; i < 45; i++) {
        for (int j = 1; j < 45; j++) {
            for (int k = 1; k < 45; k++) {
                if ((triangle_num[i] + triangle_num[j] + triangle_num[k]) == num) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    make_triangle_num();
    cin >> T;
    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;
        if (check_num(num)) {
            cout << '1' << '\n';
        } else {
            cout << '0' << '\n';
        }
    }
    return 0;
}