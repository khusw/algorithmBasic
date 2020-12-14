/*
    BOJ 11286 절댓값 힙
    https://www.acmicpc.net/problem/11286
*/

#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int n;

struct compare {
    bool operator()(const int& num1, const int& num2) {
        if (abs(num1) != abs(num2))
            return abs(num1) > abs(num2);
        else
            return num1 > num2;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    priority_queue<int, vector<int>, compare> pq;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x) {
            pq.push(x);
        } else {
            if (!pq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            } else {
                cout << "0\n";
            }
        }
    }

    return 0;
}
