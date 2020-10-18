/*
    B. Putting Bricks in the wall
    https://codeforces.com/contest/1421/problem/B
*/

#include <iostream>

using namespace std;

int T, N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        int c = 0;
        string adj[N];
        for (int i = 0; i < N; i++) cin >> adj[i];

        char sr = adj[0][1], sd = adj[1][0], ft = adj[N - 2][N - 1], fl = adj[N - 1][N - 2];

        if (sr != sd) {
            if (ft == fl && ft != sr) {
                sd = sr;
                c = 1;
                cout << c << "\n";
                cout << "2 1\n";
            } else if (ft == fl && ft == sr) {
                sr = sd;
                c = 1;
                cout << c << "\n";
                cout << "1 2\n";
            } else if (ft != fl && ft != sr) {
                sr = sd, ft = fl;
                c = 2;
                cout << c << "\n";
                cout << "1 2\n";
                cout << N - 1 << " " << N << "\n";
            } else if (ft != fl && ft == sr) {
                sr = sd, fl = ft;
                c = 2;
                cout << c << "\n";
                cout << "1 2\n";
                cout << N << " " << N - 1 << "\n";
            }
        } else {
            if (ft == fl && ft != sr && ft != sd) {
                c = 0;
                cout << c << "\n";
            } else if (ft == fl && ft == sr && ft == sd) {
                c = 2;
                cout << c << "\n";
                cout << N - 1 << " " << N << "\n";
                cout << N << " " << N - 1 << "\n";
            } else if (ft != fl && ft != sr) {
                fl = ft;
                c = 1;
                cout << c << "\n";
                cout << N << " " << N - 1 << "\n";
            } else if (ft != fl && ft == sr) {
                ft = fl;
                c = 1;
                cout << c << "\n";
                cout << N - 1 << " " << N << "\n";
            }
        }
    }

    return 0;
}