/*
    BOJ 1914 The Tower of Hanoi
    https://www.acmicpc.net/problem/1914
*/

#include <algorithm>
#include <iostream>

#define endl "\n"

using namespace std;

int n;

string merge_string(string num1, string num2) {
    long long sum = 0;
    string result;
    while (!num1.empty() || !num2.empty() || sum) {
        if (!num1.empty()) {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

void hanoi_tower(int num, char from, char by, char to) {
    if (num == 1) {
        cout << from - 'A' + 1 << " " << to - 'A' + 1 << endl;
        return;
    }
    hanoi_tower(num - 1, from, to, by);
    cout << from - 'A' + 1 << " " << to - 'A' + 1 << endl;
    hanoi_tower(num - 1, by, from, to);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    int sub;
    string num, result;

    if (n == 1) {
        result = "1";
    } else {
        num = "2";
        for (int i = 0; i < n - 1; ++i) {
            result = merge_string(num, num);
            num = result;
        }
        sub = result.back() - '0';
        result.pop_back();
        sub -= 1;
        result.push_back(sub + '0');
    }

    cout << result << endl;

    if (n <= 20) hanoi_tower(n, 'A', 'B', 'C');
    return 0;
}