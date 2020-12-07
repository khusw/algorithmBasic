/*
    PG 43162 Network
    https://programmers.co.kr/learn/courses/30/lessons/43162#
*/

#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& computers, int idx) {
    if (!computers[idx][idx]) return false;
    computers[idx][idx] = 0;
    for (int i = 0; i < computers.size(); ++i)
        if (computers[idx][i]) dfs(computers, i);
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; ++i)
        if (computers[i][i] && dfs(computers, i))
            answer++;
    return answer;
}