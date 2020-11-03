/*
    BOJ 15686 치킨 배달
    https://www.acmicpc.net/problem/15686
*/

#include <bits/stdc++.h>

#define endl "\n"
#define MAX_N 51
#define MAX_M 14
#define INF 987654321

using namespace std;

int n, m, answer;
int adj[MAX_N][MAX_N];
bool isUsed[MAX_M];
vector<pair<int, int>> house;
vector<pair<int, int>> store;

void dfs(int curIdx, int curCnt) {
	if (curIdx > store.size()) return;
	
	if (curCnt == m) {
		int cmp = 0;
		
		for (int i = 0; i < house.size(); ++i) {
			int dist = INF;
			for (int j = 0; j < store.size(); ++j) {
				if (isUsed[j]) {
					int houseX = house[i].first, houseY = house[i].second;
					int storeX = store[j].first, storeY = store[j].second;
					int d = abs(houseX - storeX) + abs(houseY - storeY);
					dist = min(dist, d);	
				}		
			}
			cmp += dist;
		}	
		answer = min(answer, cmp);
		return;
	}
	
	isUsed[curIdx] = true;
	dfs(curIdx + 1, curCnt + 1);
	
	isUsed[curIdx] = false;
	dfs(curIdx + 1, curCnt);
}

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> adj[i][j];
			if (adj[i][j] == 1) {
				house.emplace_back(make_pair(i, j));
			} else if (adj[i][j] == 2) {
				store.emplace_back(make_pair(i, j));
			}
		}
	}			
	
	answer = INF;
	dfs(0, 0);
	cout << answer << endl;
	
	return 0;
}