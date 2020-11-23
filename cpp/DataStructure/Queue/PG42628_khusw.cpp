/*
    PG 42628 이중 우선순위 큐
    https://programmers.co.kr/learn/courses/30/lessons/42628#
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    for (int i = 0; i < operations.size(); ++i) {
        string temp = operations[i];
        char order = temp[0];
        int num = stoi(temp.substr(2, temp.length() - 2));

        if (order == 'I') {
            ms.insert(num);
        } else {
            if (!ms.empty()) {
                if (num == 1) {
                    auto iter = ms.end();
                    --iter;
                    ms.erase(iter);
                } else {
                    auto iter = ms.begin();
                    ms.erase(iter);
                }
            }
        }
    }

    answer.resize(2, 0);
    if (!ms.empty()) {
        auto iter = ms.begin();
        answer[1] = *iter;
        iter = ms.end();
        --iter;
        answer[0] = *iter;
    }

    return answer;
}