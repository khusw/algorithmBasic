/*
    BOJ 1620 나는야 포켓몬 마스터 이다솜
    https://www.acmicpc.net/problem/1620
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<string> arr;
vector<pair<string, int>> sort_vec;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    string s;
    arr.push_back("");
    for (int i = 1; i <= N; i++) {
        cin >> s;
        arr.push_back(s);
        sort_vec.push_back({s, i});
    }

    sort(sort_vec.begin(), sort_vec.end());

    string in_str;
    for (int i = 1; i <= M; i++) {
        cin >> in_str;

        if (in_str[0] >= '0' && in_str[0] <= '9') {
            // 입력이 숫자인 경우
            int index = stoi(in_str);
            cout << arr[index] << '\n';
        } else {
            // 입력이 문자이면 이진 탐색을 수행해서 O(logN) 으로 줄인다.
            int begin = 0;
            int last = N - 1;
            int mid = 0;
            while (begin <= last) {
                mid = (begin + last) / 2;
                if (sort_vec[mid].first == in_str) {
                    cout << sort_vec[mid].second << '\n';
                    break;
                } else if (sort_vec[mid].first < in_str) {
                    begin = mid + 1;
                } else {
                    last = mid - 1;
                }
            }
        }
    }

    return 0;
}

/*
    변수의 타입 처리 관련하여,
    template 를 쓰는 경우, main 함수에서 오류를 내포하기 때문에
    쓰지 않는 것이 좋을 것 같다
    기회가 되면 template 에 대해서 다시 정리해보는게 좋겠다.

    입력이 key 가 들어오면 O(1) 에 처리가능하고
    value 가 들어오면 O(logN) 에 처리 되도록
    이진 탐색 구조를 사용해야 함.

    이 문제는 주의할것이
    O(1) 을 위한 컨테이너와 O(logN) 을 위한 컨테이너가 따로 있어야 함.
    왜냐면 O(1) 은 그냥 배열에서 인덱스 찾아가기 하면 바로 O(1) 이 되지만,
    O(logN) 은 이진 탐색을 해야 하는데, 이진 탐색의 경우, 이미 정렬되어 있다는 가정하에 진행되는 것이기 때문임.

    항상 단순 무식하게 푸는 방법을 생각하지 말고,
    O(MN), O(N^2) 은 안된다고 생각하고
    O(logN) - 이진탐색
    O(1) - 해시맵
    O(NlogN) - 퀵소트

    등을 생각하면서 어떻게 해야 줄일까를 고민해야함.
*/