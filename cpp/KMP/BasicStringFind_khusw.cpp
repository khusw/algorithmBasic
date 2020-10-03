#include <iostream>

using namespace std;

int findString(string parent, string pattern) {
    int parentSize = parent.size();
    int patternSize = pattern.size();
    for (int i = 0; i <= parentSize - patternSize; i++) {
        bool finded = true;
        for (int j = 0; j < patternSize; j++) {
            if (parent[i + j] != pattern[j]) {
                finded = false;
                break;
            }
        }
        if (finded) {
            return i;
        }
    }
    return -1;
}

int main() {
    string parent = "Hello World";
    string pattern = "llo W";
    int result = findString(parent, pattern);
    if (result == -1) {
        printf("찾을 수 없음");
    } else {
        printf("%d 에서 찾았다. ", result);
    }
    return 0;
}
