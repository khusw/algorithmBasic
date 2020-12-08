/*
    PG 12913 땅따먹기
    https://programmers.co.kr/learn/courses/30/lessons/12913
*/

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int> > land) {
    int answer = 0, size = land.size();

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < 4; ++j) {
            int num = 0;
            for (int k = 0; k < 4; ++k) {
                if (j != k) num = max(num, land[i][j] + land[i - 1][k]);
            }
            land[i][j] = num;
        }
    }

    for (int i = 0; i < 4; ++i) answer = max(answer, land[size - 1][i]);

    return answer;
}