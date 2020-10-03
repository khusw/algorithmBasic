/*
    BOJ 1620 나는야 포켓몬 마스터 이다솜
    https://www.acmicpc.net/problem/1620
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<string> arr;
vector<pair<string, int>> sort_vec;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    string s;
    arr.push_back("");
    for (int i = 1; i <= N; i++) {
        cin >> s;
        arr.push_back(s);
        sort_vec.push_back({s, i});
    }

    sort(sort_vec.begin(), sort_vec.end());

    string in_str;
    for (int i = 1; i <= M; i++) {
        cin >> in_str;

        if (in_str[0] >= '0' && in_str[0] <= '9') {
            int index = stoi(in_str);
            cout << arr[index] << '\n';
        } else {
            int begin = 0;
            int last = N - 1;
            int mid = 0;
            while (begin <= last) {
                mid = (begin + last) / 2;
                if (sort_vec[mid].first == in_str) {
                    cout << sort_vec[mid].second << '\n';
                    break;
                } else if (sort_vec[mid].first < in_str) {
                    begin = mid + 1;
                } else {
                    last = mid - 1;
                }
            }
        }
    }

    return 0;
}