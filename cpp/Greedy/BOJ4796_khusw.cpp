/*
    BOJ 4796 캠핑
    https://www.acmicpc.net/problem/4796
*/

#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int L, P, V;
    int i = 0;
    while (true) {
        i++;
        int answer = 0;
        cin >> L >> P >> V;
        if (!L && !P && !V) break;

        while (V > 0) {
            if (V >= L)
                answer += L;
            else
                answer += V;
            V -= P;
        }
        cout << "Case " << i << ": " << answer << '\n';
    }

    return 0;
}