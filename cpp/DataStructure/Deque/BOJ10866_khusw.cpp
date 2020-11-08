/*
    BOJ 10866 덱
    https://www.acmicpc.net/problem/10866
*/
#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

string input;
deque<int> dq;
int n, num;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i <= n; ++i) {
        getline(cin, input);
        if (input.substr(0, 9) == "push_back") {
            num = stoi(input.substr(10, input.length() - 10));
            dq.push_back(num);
        }
        if (input.substr(0, 10) == "push_front") {
            num = stoi(input.substr(11, input.length() - 11));
            dq.push_front(num);
        }
        if (input.substr(0, 9) == "pop_front") {
            if (dq.empty())
                cout << "-1" << endl;
            else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        if (input.substr(0, 8) == "pop_back") {
            if (dq.empty())
                cout << "-1" << endl;
            else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        if (input.substr(0, 4) == "size") cout << dq.size() << endl;
        if (input.substr(0, 5) == "empty") {
            if (dq.empty())
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        if (input.substr(0, 5) == "front") {
            if (dq.empty())
                cout << "-1" << endl;
            else
                cout << dq.front() << endl;
        }
        if (input.substr(0, 4) == "back") {
            if (dq.empty())
                cout << "-1" << endl;
            else
                cout << dq.back() << endl;
        }
    }

    return 0;
}