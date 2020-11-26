/*
    BOJ 13335 Truck
    https://www.acmicpc.net/problem/13335
*/

#include <bits/stdc++.h>

using namespace std;

int N, W, L;
int answer;
vector<int> truck;
queue<int> bridge;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> W >> L;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        truck.push_back(num);
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        while (1) {
            if (bridge.size() == W) {
                sum -= bridge.front();
                bridge.pop();
            }
            if (sum + truck[i] <= L) break;
            bridge.push(0);
            answer++;
        }
        bridge.push(truck[i]);
        sum += truck[i];
        answer++;
    }

    answer += W;
    cout << answer;

    return 0;
}