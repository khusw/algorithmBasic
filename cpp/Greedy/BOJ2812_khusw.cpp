/*  
    BOJ 2812 크게 만들기
    https://www.acmicpc.net/problem/2812
*/

#include <deque>
#include <iostream>
#include <string>

using namespace std;

int N, K;
string str;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    cin >> str;

    deque<char> dq;

    for (int i = 0; i < str.length(); ++i) {
        while (K && !dq.empty() && dq.back() < str[i]) {
            dq.pop_back();
            K--;
        }
        dq.push_back(str[i]);
    }

    for (int i = 0; i < dq.size() - K; ++i) cout << dq[i];

    return 0;
}