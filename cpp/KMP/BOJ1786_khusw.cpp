#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pCount;
vector<int> pPos;

vector<int> makePi(string pattern) {
    int patternSize = pattern.size();
    vector<int> pi(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = pi[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

void KMP(string parent, string pattern) {
    vector<int> pi = makePi(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for (int i = 0; i < parentSize; i++) {
        while (j > 0 && parent[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (parent[i] == pattern[j]) {
            if (j == patternSize - 1) {
                pPos.push_back(i - patternSize + 2);
                j = pi[j];
                pCount++;
            } else {
                j++;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string parent, pattern;
    getline(cin, parent);
    getline(cin, pattern);
    KMP(parent, pattern);

    printf("%d\n", pCount);
    for (int i = 0; i < pPos.size(); i++) {
        printf("%d ", pPos[i]);
    }
    return 0;
}