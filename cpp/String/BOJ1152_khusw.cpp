/*
    BOJ 1152 단어의 갯수 
    https://www.acmicpc.net/problem/1152
*/
#include <iostream>
#include <string>

using namespace std;

string inStr;
int spaceCount = 1;

void countWord(string str) {
    int length = str.size();

    if (str[0] == ' ') {
        spaceCount = 0;
    }

    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }

    if (str[length - 1] == ' ') {
        spaceCount--;
    }

    cout << spaceCount;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    getline(cin, inStr);

    countWord(inStr);

    return 0;
}