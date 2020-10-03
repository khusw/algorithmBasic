
#include <iostream>
#include <vector>

using namespace std;

vector<int> makePi(string pattern) {
    int patternSize = pattern.size();
    vector<int> pi(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

void KMP(string parent, string pattern) {
    vector<int> table = makePi(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for (int i = 0; i < parentSize; i++) {
        while (j > 0 && parent[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (parent[i] == pattern[j]) {
            if (j == patternSize - 1) {
                printf("find string at %d \n", i - patternSize + 2);
                j = table[j];
            } else {
                j++;
            }
        }
    }
}

int main() {
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    KMP(parent, pattern);
    return 0;
}