/*
    BOJ 3613 Java VS C++
    https://www.acmicpc.net/problem/3613
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;

    bool isCpp = false, isJava = false, isError = false;
    string result;

    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            if (!i || isCpp) {
                isError = true;
                break;
            }

            result += '_';
            result += str[i] - 'A' + 'a';
            isJava = true;
        } else if (str[i] == '_') {
            if (!i || isJava || i == str.length() - 1 || str[i + 1] == '_' || isupper(str[i + 1])) {
                isError = true;
                break;
            }

            result += str[i + 1] - 'a' + 'A';
            i++;
            isCpp = true;
        } else {
            result += str[i];
        }
    }

    if (isError)
        cout << "Error!\n";
    else
        cout << result << '\n';

    return 0;
}
