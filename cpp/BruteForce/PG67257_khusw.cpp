/*
    PG 67257 수식 최대화
    https://programmers.co.kr/learn/courses/30/lessons/67257
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void divide(string& exp, vector<ll>& nums, vector<char>& ops) {
    ll num = 0;
    for (int i = 0; i < exp.length(); ++i) {
        if (exp[i] >= '0') {
            num *= 10;
            num += exp[i] - '0';
        } else {
            nums.push_back(num);
            ops.push_back(exp[i]);
            num = 0;
        }
    }
    nums.push_back(num);
}

ll cal(ll num1, ll num2, char op) {
    if (op == '+')
        return num1 + num2;
    else if (op == '-')
        return num1 - num2;
    else if (op == '*')
        return num1 * num2;
    return -1;
}

ll solution(string expression) {
    ll answer = 0;

    vector<ll> nums;
    vector<char> ops;
    divide(expression, nums, ops);

    string opOrder = "+-*";
    sort(opOrder.begin(), opOrder.end());

    do {
        queue<ll, deque<ll>> numQ2, numQ1(deque<ll>(nums.begin(), nums.end()));
        queue<char, deque<char>> opQ2, opQ1(deque<char>(ops.begin(), ops.end()));

        for (int i = 0; i < 3; ++i) {
            ll temp = numQ1.front();
            numQ1.pop();

            while (!opQ1.empty()) {
                if (opQ1.front() == opOrder[i])
                    temp = cal(temp, numQ1.front(), opQ1.front());
                else {
                    opQ2.push(opQ1.front());
                    numQ2.push(temp);
                    temp = numQ1.front();
                }
                opQ1.pop();
                numQ1.pop();
            }
            numQ2.push(temp);

            if (numQ2.size() == 1) answer = max(abs(numQ2.front()), answer);
            numQ1.swap(numQ2);
            opQ1.swap(opQ2);
        }

    } while (next_permutation(opOrder.begin(), opOrder.end()));

    return answer;
}