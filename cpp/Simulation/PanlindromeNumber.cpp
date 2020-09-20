/*
    BOJ 1259 팰린드롬 수
    https://www.acmicpc.net/problem/1259
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (1) {
        string tmp, reverse_tmp;
        cin >> tmp;
        if (tmp == "0") break;
        int size = tmp.length();
        for (int i = size - 1; i > -1; i--) {
            reverse_tmp.push_back(tmp[i]);
        }
        if (tmp == reverse_tmp)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}