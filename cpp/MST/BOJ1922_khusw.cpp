/*
    BOJ 1922 네트워크 연결
    https://www.acmicpc.net/problem/1922
*/

#include <algorithm>
#include <iostream>

using namespace std;

int uf[1001];  // array of union-find
int N, M, result, cnt;

class Edge {
   private:
    int u, v, w;

   public:
    Edge();
    Edge(int a, int b, int c);
    bool operator<(const Edge& e);
    int u_getter();
    int v_getter();
    int w_getter();
};

Edge::Edge() {
    this->u = -1, this->v = -1, this->w = 0;
}

Edge::Edge(int a, int b, int c) {
    this->u = a, this->v = b, this->w = c;
}

bool Edge::operator<(const Edge& e) {
    return this->w < e.w;
}

int Edge::u_getter() {
    return this->u;
}

int Edge::v_getter() {
    return this->v;
}

int Edge::w_getter() {
    return this->w;
}

// union-find's find
int find(int a) {
    if (uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

// union-find's union
bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    uf[b] = a;
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    Edge e[100001];
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = Edge(u, v, w);
    }

    sort(e, e + M);

    fill(uf, uf + N, -1);

    for (int i = 0;; i++) {
        int u = e[i].u_getter();
        int v = e[i].v_getter();
        int w = e[i].w_getter();
        if (merge(u, v)) {
            result += w;
            if (++cnt == N - 1) break;
        }
    }

    cout << result;

    return 0;
}