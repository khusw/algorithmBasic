#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> vec = {1, 2, 3};

void permutation(int start, int end) {
    if (start == end) {
        for (auto it : vec) {
            cout << it << " ";
        }
        cout << '\n';
    } else {
        for (int i = start; i <= end; i++) {
            swap(vec[start], vec[i]);
            permutation(start + 1, end);
            swap(vec[start], vec[i]);
        }
    }
}

int main() {
    permutation(0, 2);
    return 0;
}