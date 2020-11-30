/*
    PG 17676 추석 트래픽
    https://programmers.co.kr/learn/courses/30/lessons/17676
*/

#include <bits/stdc++.h>

using namespace std;

int time_to_num(string& time_line) {
    string hour = time_line.substr(11, 2);
    string minute = time_line.substr(14, 2);
    string second = time_line.substr(17, 6);
    second.erase(second.begin() + 2, second.begin() + 3);

    int h = stoi(hour) * 60 * 60 * 1000;
    int m = stoi(minute) * 60 * 1000;
    int s = stoi(second);

    return h + m + s;
}

int process_to_num(string& time_line) {
    string temp = time_line.substr(24, time_line.length() - 25);
    double num = stod(temp);
    int ret = num * 1000;
    return ret;
}

int solution(vector<string> lines) {
    int answer = 0, size = lines.size();

    vector<int> process, end;
    for (int i = 0; i < size; ++i) {
        string tmp = lines[i];
        int end_time = time_to_num(tmp);
        int process_time = process_to_num(tmp);

        end.push_back(end_time);
        process.push_back(process_time);
    }

    int next_start_time, fur_time;
    for (int i = 0; i < size; ++i) {
        int temp = 0;
        fur_time = end[i] + 1000;
        for (int j = i + 1; j < size; ++j) {
            next_start_time = end[j] - process[j] + 1;
            if (next_start_time < fur_time) {
                temp++;
                continue;
            }
        }
        if (temp > answer) answer = temp;
    }

    return answer + 1;
}