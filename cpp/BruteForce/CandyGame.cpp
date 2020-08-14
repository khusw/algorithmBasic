/*
    BOJ 3085 사탕 게임
    https://www.acmicpc.net/problem/3085

    봄보니 게임
    N*N 행렬이 주어지고 이 행렬에 1*1 크기의 사탕으로 꽉 채워넣는다.
    게임 플레이어는 사탕의 색이 다른 인접한 두칸을 고르고, 고른 칸에 들어 있는 사탕을 서로 교환한다.
    모두 같은 색으로 이뤄진 행 또는 열 하나를 골라서 그곳에 해당하는 모든 사탕을 다 먹는다.

    입력은 사탕이 N*N 행렬로 주어지며, 이때 플레이어가 먹을 수 있는 사탕의 최대 갯수를 구하는 프로그램을 작성해야한다.
    N 은 보드의 크기 (3 ~ 50)
    C 는 빨간색, P 는 파란색, Z 는 초록색, Y 는 노란색 이다.

    주의할점은 행이나 열이 빙고처럼 한줄 완성되야 할 필요는 없다.
    예를들면
    N = 5
    YCPZY
    CYZZP
    CCPPP
    YCYZC
    CPPZZ

    에서 4행의 서로 붙어있는 YC 를 서로 자리바꿈하여
    CYYZC 로 행을 전환하면 C 가 4개인 상황이 되어, 먹을 수 있는 사탕 갯수가 4개가 된다.
    이 예제에 대한 답이 4개인것으로 봐서는
    사탕의 위치를 바꾸는것은 1회만 수행하는 듯 하다.
    여러번 수행이 가능했다면 C 를 1열 한줄로 완성이 가능하기 때문에
    답이 5였을 것이다. 그러나 4가 된것으로 봐서 사탕 위치 전환은 1회만 가능하다.

    1회 전환 이후에 최대로 일치하는 사탕의 갯수를 찾아서 리턴하는게 이문제의 핵심
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int answer;

int max_cnt(vector<string>& vec_str) {
    int vec_len = vec_str.size();
    int result = 1;

    // 행으로 탐색
    for (int i = 0; i < vec_len; i++) {
        int cnt = 1;
        int str_len = vec_str[i].length();
        for (int j = 0; j < str_len - 1; j++) {
            if (vec_str[i][j] == vec_str[i][j + 1]) {
                cnt++;
            } else {
                result = max(result, cnt);
                cnt = 1;
            }
        }
        result = max(result, cnt);
    }

    // 열로 탐색
    for (int i = 0; i < vec_len; i++) {
        int cnt = 1;
        int str_len = vec_str[i].length();
        for (int j = 0; j < str_len - 1; j++) {
            if (vec_str[j][i] == vec_str[j + 1][i]) {
                cnt++;
            } else {
                result = max(result, cnt);
                cnt = 1;
            }
        }
        result = max(result, cnt);
    }

    return result;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    vector<string> in_str;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        in_str.push_back(str);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            // 양옆 변화
            swap(in_str[i][j], in_str[i][j + 1]);
            answer = max(answer, max_cnt(in_str));
            swap(in_str[i][j], in_str[i][j + 1]);  // 행렬 원상 복귀

            // 위아래 변화
            swap(in_str[j][i], in_str[j + 1][i]);
            answer = max(answer, max_cnt(in_str));
            swap(in_str[j][i], in_str[j + 1][i]);  // 행렬 원상 복귀
        }
    }

    printf("%d", answer);

    return 0;
}

/*
    이 문제를 풀면서 간과했던 것은
    행(양 옆) 으로 바꾸기(swap) 를 진행해야 하는것도 맞지만,
    열(위 아래) 로도 바꾸기(swap) 을 진행해야 했다.

    그점을 빼먹었기 때문에, 전체 케이스를 통과하지 못했다.

    또한 갯수를 카운팅할때,
    한 케이스 (양 옆을 서로 바꿨을때 일치하는 경우) 당
    가져갈수 있는 사탕의 갯수는 2개다. 
    그러니까 처음에 초기화 시에 값이 0 이 아니라 1이 되어야 한다.

    그리고 마지막으로 한번 swap 을 진행했다면
    다음 차례엔 원래 배열을 가지고 그대로 진행해야 하기 때문에
    swap 을 한 차례 또 수행해서 원래대로 돌려 놓는다.
*/