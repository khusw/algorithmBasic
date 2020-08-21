/*
    BOJ 1038 감소하는 수
    https://www.acmicpc.net/problem/1038

    감소하는 수란 가장 큰 자리수의 값 부터 가장 작은 자리수의 값 까지 
    값이 감소 하는 모양이라면 감소하는 수라 부른다

    921, 752 는 감소하는 수이나, 922, 755 는 감소하는 수가 아니다.

    N 번째 감소하는 수를 찾는 프로그램을 짜는 것이 이 문제의 목표
    0은 0번째 감소하는 수이며,
    1은 1번째 감소하는 수로 칭한다.
    0,1,2,3,4... ,9
    10,20,21,30,31,32,40,41,42,43,50,51,52,53,54,....

    10으로 나누면 몫만 나오지 맨앞 자리수는 알 수 없다.
    역으로 생각해서 % 연산을 하면 맨 뒷자리수는 알 수 있으므로,
    % 연산을 한 결과들을 쭉 담아서 그 값들이 오름차순이면 결국 감소하는 수 인것이다.

    1. 먼저 맨처음 10으로 나눴을때, 값이 0이 된다 == 일의 자리수이다
    -> 일의 자리수라면 그대로 출력 (판별하는 기능 없어도됨)
    2. 1이 아닌경우 == 십의자리수 이상이다.
    -> 값을 10으로 % 연산을 계속수행해서 결과들을 담는다.
    그 결과들을 쭉 나열 했을 때, 오름차순이 아니라면 결국은 감소하는 수가 아니며,
    반대의 경우 감소하는 수로 칠 수 있다.
    그리고 굳이 결과물을 계속 쭉 담지 않아도 bool 변수를 통해서 판별이 가능.
*/

#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> decrease;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    int cnt = 0;
    int i, j, tmp;

    if (N <= 10) {
        cout << N << '\n';
    } else if (N == 1022) {
        cout << 9876543210 << '\n';
    } else if (N >= 1023) {
        cout << "-1" << '\n';
    } else {
        for (i = 1; i < 10; i++) {
            decrease.push(i);
            cnt++;
        }

        while (cnt < N) {
            i = decrease.front();
            decrease.pop();
            tmp = i % 10;

            for (j = 0; j < tmp; j++) {
                decrease.push(i * 10 + j);
                cnt++;
                if (cnt == N) {
                    cout << i * 10 + j << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}

/*
    또 다른 풀이법 (재귀함수를 이용한 방식)

    #include <algorithm>
    #include <iostream>
    #include <vector>

    typedef long long ll;

    using namespace std;

    vector<ll> vec;
    int N;

    void solution(ll index, int cnt) {
        if (cnt > 10) return;

        vec.push_back(index);

        for (int i = 0; i < 10; i++) {
            if (index % 10 > i) {
                solution(index * 10 + i, cnt + 1);
            }
        }
        return;
    } 

    int main() {
        cin.tie(0);
        ios_base::sync_with_stdio(0);

        cin >> N;

        for (int i = 0; i < 10; i++) {
            solution(i, 1);
        }

        sort(vec.begin(), vec.end());

        ll answer = (vec.size() <= N) ? -1 : vec[N];

        cout << answer;

        return 0;
    }
*/