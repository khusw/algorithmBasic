/*
    단지번호붙이기 (BOJ 2667)
    https://www.acmicpc.net/problem/2667

    첫번째 입력에 지도의 크기가 주어지고 (지도의 크기는 곧 총 노드의 갯수를 의미한다)
    다음 줄 입력 부터는 0,1 로 구성된 입력이 들어온다.
    이는 곧 인접 행렬을 의미하는 것과 동일하다.

    출력은 첫번째 줄에 총 단지수가 몇개인지 출력하는 것이며(),
    둘째 줄에는 단지별 집의 갯수를 오름차순으로 출력한다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt;                // 총 노드의 수 (5 ~ 25), 갯수 출력 변수
int checked[25][25];       // 방문 여부를 나타내는 배열
int dx[4] = {0, 1, 0, -1}; // 하, 우, 상, 좌
int dy[4] = {-1, 0, 1, 0}; // dx 와 동일
string adj[25];            // 인접노드를 나타내는 배열
vector<int> answer;        // 답안 출력을 위한 변수

void DFS(int i, int j)
{
    checked[i][j] = true;
    cnt++;

    for (int k = 0; k < 4; k++)
    {
        int newX = i + dx[k];
        int newY = j + dy[k];

        if ((0 <= newX && newX < n) && (0 <= newY && newY < n))
        {
            if (adj[newX][newY] == '1' && !checked[newX][newY])
            {
                DFS(newX, newY);
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n; // 지도의 크기 n 을 입력
    for (int i = 0; i < n; i++)
    {
        cin >> adj[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == '1' && !checked[i][j])
            {
                // 행렬의 해당 번지수의 값이 1 이면서, 방문하지 않은 경우
                cnt = 0;
                DFS(i, j);
                answer.push_back(cnt);
            }
        }
    }

    cout << answer.size() << '\n'; // answer 의 size 가 총 단지수를 의미한다.
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << '\n'; // answer 각각 내부의 int 값이 단지 내의 주거지 수를 의미한다.
    }
    return 0;
}