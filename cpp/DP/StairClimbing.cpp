/*
    BOJ 2579 계단 오르기
    https://www.acmicpc.net/problem/2579

    계단이 여러개 주어지고, 
    각 계단 별로 밟기 위한 비용이 주어짐

    계단을 오르기 위한 규칙은 
    1. 한번에 한 계단 또는 두 계단 씩 오를 수 있음
    2. 연속적으로 3개의 계단을 밟아서는 안됨
    3. 마지막 계단은 반드시 밟아야 함
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    int adj[300];
    int D[300];

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> adj[i];
    }

    D[0] = adj[0];
    D[1] = max(adj[0] + adj[1], adj[1]);
    D[2] = max(adj[0] + adj[2], adj[1] + adj[2]);

    for (int i = 3; i < T; i++)
    {
        D[i] = max(D[i - 2] + adj[i], D[i - 3] + adj[i - 1] + adj[i]);
    }

    cout << D[T - 1];
    return 0;
}