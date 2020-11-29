/*
    PG 64065 튜플
    https://programmers.co.kr/learn/courses/30/lessons/64065
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool comp(pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2) {
    return p1.second < p2.second;
}

vector<int> solution(string str) {
    vector<int> answer;
    vector<pair<pair<int, int>, int>> vec;  // s, e, cnt
    str.erase(0, 1);
    str.pop_back();
    int len = str.length(), cnt = 0, s = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == '{')
            s = i;
        else if ('0' <= str[i] && str[i] <= '9')
            cnt++;
        else if (str[i] == '}') {
            vec.push_back(make_pair(make_pair(s, i), cnt));
            cnt = 0;
        }
    }
    sort(vec.begin(), vec.end(), comp);
    for (int i = 0; i < vec.size(); ++i) {
        int start = vec[i].first.first, end = vec[i].first.second;
        string temp;
        for (int j = start; j <= end; ++j) {
            if ('0' <= str[j] && str[j] <= '9') temp.push_back(str[j]);
            if (str[j] == ',' || str[j] == '}' && !temp.empty()) {
                int num = stoi(temp);
                if (answer.empty())
                    answer.push_back(num);
                else {
                    auto result = find(answer.begin(), answer.end(), num);
                    if (result == answer.end()) answer.push_back(num);
                }
                temp = "";
            }
        }
    }
    return answer;
}