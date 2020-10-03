/* 
    BOJ 7662 이중 우선순위 큐
    https://www.acmicpc.net/problem/7662
*/

#include <iostream>
#include <set>

using namespace std;

int T, k, num;
char ch;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k;
        multiset<int> ms;
        for (int j = 0; j < k; j++) {
            cin >> ch >> num;
            if (ch == 'I') {
                ms.insert(num);
            } else {
                if (!ms.empty()) {
                    if (num == 1) {
                        auto iter = ms.end();
                        iter--;
                        ms.erase(iter);
                    } else {
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if (ms.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            auto iter = ms.end();
            iter--;
            cout << *iter << " " << *ms.begin() << '\n';
        }
    }

    return 0;
}