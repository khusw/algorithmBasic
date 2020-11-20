/*
    PG 42839 소수 찾기
    https://programmers.co.kr/learn/courses/30/lessons/42839
*/
#include <bits/stdc++.h>

using namespace std;

bool findPrime(int x) {
    if (x == 1) return false;
    if (x == 2) return true;

    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0, len = numbers.length();
    string s = numbers;
    sort(s.begin(), s.end(), greater<char>());
    vector<bool> prime(stoi(s) + 1);

    prime[0] = false;
    for (long long i = 1; i < prime.size(); ++i) prime[i] = findPrime(i);

    sort(numbers.begin(), numbers.end());
    set<int> ans;

    do {
        for (int i = 1; i <= numbers.size(); ++i) {
            string temp = numbers.substr(0, i);
            if (prime[stoi(temp)]) {
                ans.insert(stoi(temp));
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    answer = ans.size();
    return answer;
}