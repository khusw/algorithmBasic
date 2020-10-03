/*
    BOJ 5397 키로거
    https://www.acmicpc.net/problem/5397
*/
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        string L;
        cin >> L;

        list<char> ans;
        list<char>::iterator ans_iter = ans.begin();

        int L_len = L.size();
        int L_idx = 0;

        while (L_idx < L_len) {
            switch (L[L_idx]) {
                case '<':
                    if (ans_iter != ans.begin())
                        ans_iter--;
                    break;
                case '>':
                    if (ans_iter != ans.end())
                        ans_iter++;
                    break;
                case '-':
                    if (ans_iter != ans.begin())
                        ans.erase((--ans_iter)++);
                    break;
                default:
                    ans.insert(ans_iter, L[L_idx]);
                    break;
            }
            L_idx++;
        }
        for (auto x : ans)
            printf("%c", x);
        printf("\n");
    }
    return 0;
}