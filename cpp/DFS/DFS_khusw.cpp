#include <iostream>
#include <vector>

using namespace std;

int num = 7;
int c[7];
vector<int> adj[8];

void dfs(int x) {
    if (c[x])
        return;
    c[x] = true;
    cout << x << ' ';
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i];
        dfs(y);
    }
}

int main() {
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[2].push_back(5);
    adj[5].push_back(2);

    adj[3].push_back(6);
    adj[6].push_back(3);

    adj[3].push_back(7);
    adj[7].push_back(3);

    adj[4].push_back(5);
    adj[5].push_back(4);

    adj[6].push_back(7);
    adj[7].push_back(6);

    dfs(1);
    return 0;
}
