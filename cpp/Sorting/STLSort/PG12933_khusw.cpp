/*
    PG 12933 내림차순 정렬
    https://programmers.co.kr/learn/courses/30/lessons/12933  
*/

#include <algorithm>
#include <string>

using namespace std;

bool comp(char ch1, char ch2) {
    return ch1 > ch2;
}

long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n);
    sort(str.begin(), str.end(), comp);
    answer = stoll(str);
    return answer;
}