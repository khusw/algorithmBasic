/*
    PG 42746 가장 큰 수
    https://programmers.co.kr/learn/courses/30/lessons/42746#
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(string& a, string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> vec;
    for (int i = 0; i < numbers.size(); ++i) {
        string tmp = to_string(numbers[i]);
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end(), comp);

    for (int i = 0; i < vec.size(); ++i) answer += vec[i];

    bool flag = true;
    for (int i = 0; i < answer.length(); ++i) {
        if (answer[i] != '0') {
            flag = false;
            break;
        }
    }

    if (flag) answer = "0";

    return answer;
}