/*
    BOJ 2824 GCD
    https://www.acmicpc.net/problem/2824
*/

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

typedef long long ll;

const ll MOD = 1e9;

int n, m;

void primeFactorize(map<ll, ll>& mp, ll x) {
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            x /= i;
            mp[i]++;
        }
    }
    if (x != 1) mp[x]++;
}

int digitLen(ll x) {
    int cnt = 0;
    while (x) {
        x /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    map<ll, ll> a;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        primeFactorize(a, x);
    }

    cin >> m;
    map<ll, ll> b;
    for (int i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        primeFactorize(b, x);
    }

    map<ll, ll> fin;
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (b.count(it->first)) {
            fin[it->first] = min(it->second, b[it->first]);
        }
    }

    ll answer = 1;
    bool exceeded = false;
    for (auto it = fin.begin(); it != fin.end(); ++it) {
        int t = it->second;
        for (int i = 0; i < t; ++i) {
            answer *= it->first;
            if (answer >= MOD) {
                exceeded = true;
                answer %= MOD;
            }
        }
    }

    if (exceeded) {
        int appendFront = 9 - digitLen(answer);
        for (int i = 0; i < appendFront; ++i) {
            cout << 0;
        }
        cout << answer << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}