
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCC;
stack<int> s;

int DFS(int x) {
    d[x] = ++id;
    s.push(x);

    int parent = d[x];
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i];
        if (d[y] == 0)
            parent = min(parent, DFS(y));
        else if (!finished[y])
            parent = min(parent, d[y]);
    }

    if (parent == d[x]) {
        vector<int> scc;
        while (1) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t == x)
                break;
        }
        SCC.push_back(scc);
    }

    return parent;
}

int main() {
    int v = 11;
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(7);
    adj[6].push_back(5);
    adj[7].push_back(6);
    adj[8].push_back(9);
    adj[9].push_back(10);
    adj[10].push_back(11);
    adj[11].push_back(3);
    adj[11].push_back(8);

    for (int i = 1; i <= v; i++) {
        if (d[i] == 0)
            DFS(i);
    }
    printf("SCC 의 갯수 : %d\n", SCC.size());
    for (int i = 0; i < SCC.size(); i++) {
        printf("%d번째 SCC : ", i + 1);
        for (int j = 0; j < SCC[i].size(); j++) {
            printf("%d ", SCC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
