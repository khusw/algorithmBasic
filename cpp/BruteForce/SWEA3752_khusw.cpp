/*
    SWEA 3752 가능한 시험 점수
    https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn&categoryId=AWHPkqBqAEsDFAUn&categoryType=CODE
*/

#include <algorithm>
#include <cstring>
#include <iostream>

#define endl "\n"

using namespace std;

int score[101];
int result[10001];
int n, cnt;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        cin >> n;

        memset(result, 0, sizeof(result));
        memset(score, 0, sizeof(score));
        cnt = 0;
        int max_val = 0;
        result[0] = 1;  // 0 은 항상 포함됨

        for (int i = 0; i < n; ++i) {
            cin >> score[i];
            max_val += score[i];
            for (int j = max_val; j >= 0; --j) {
                if (result[j] > 0) result[j + score[i]]++;  // 이전의 값과 자기자신을 더한 값 카운팅
            }
            result[score[i]]++;  // 자기 자신 카운팅
        }

        for (int i = 0; i < 10001; ++i) {
            if (result[i] > 0) cnt++;
        }

        cout << "#" << tc << " " << cnt << endl;
    }
    return 0;
}