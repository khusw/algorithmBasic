/*
    BOJ 1708 볼록 껍질
    https://www.acmicpc.net/problem/1708
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>

#define MAX 100000

using namespace std;

struct Point {
    int x, y;
    int p, q;
    Point() : Point(0, 0, 1, 0) {}
    Point(int x1, int y1) : Point(x1, y1, 1, 0) {}
    Point(int x1, int y1, int p1, int q1) : x(x1), y(y1), p(p1), q(q1) {}
    bool operator<(const Point& O) {
        if (1LL * q * O.p != 1LL * p * O.q) return 1LL * q * O.p < 1LL * p * O.q;
        if (y != O.y) return y < O.y;
        return x < O.x;
    }
};

long long ccw(const Point& A, const Point& B, const Point& C) {
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    Point p[MAX];

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    }

    sort(p, p + n);

    for (int i = 1; i < n; ++i) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }

    sort(p + 1, p + n);

    stack<int> st;
    st.push(0);
    st.push(1);

    int next = 2;

    while (next < n) {
        while (st.size() >= 2) {
            int first, second;
            first = st.top();
            st.pop();
            second = st.top();
            if (ccw(p[second], p[first], p[next]) > 0) {
                st.push(first);
                break;
            }
        }
        st.push(next++);
    }

    cout << st.size();

    return 0;
}