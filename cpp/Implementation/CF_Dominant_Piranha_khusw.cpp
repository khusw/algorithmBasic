/*  
    C. Dominant Piranha
    https://codeforces.com/contest/1433/problem/C
*/

#include <iostream>
#include <vector>

using namespace std;

int T;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int j = 0; j < n; j++) cin >> vec[j];

        int maxNum = 0, idx = -1;
        for (int j = 0; j < n - 1; j++) {
            if (vec[j] > vec[j + 1] && maxNum < vec[j] && vec[j] != vec[j + 1]) {
                maxNum = vec[j];
                idx = j;
            } else if (vec[j] < vec[j + 1] && maxNum < vec[j + 1] && vec[j] != vec[j + 1]) {
                maxNum = vec[j + 1];
                idx = j + 1;
            }
        }

        if (idx == -1)
            cout << -1 << "\n";
        else
            cout << idx + 1 << "\n";
    }

    return 0;
}