/*
    PG 12953 N 개의 최소 공배수
    https://programmers.co.kr/learn/courses/30/lessons/12953
*/

#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }

int solution(vector<int> arr) {
    int answer = arr[0];
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); ++i) answer = lcm(answer, arr[i]);
    return answer;
}