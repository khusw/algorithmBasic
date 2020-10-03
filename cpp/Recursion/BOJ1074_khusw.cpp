#include <cmath>
#include <iostream>

using namespace std;

int N, r, c, cnt;

void recursion(int row, int col, int range) {
    if (row == r && col == c) {
        cout << cnt;
        return;
    }

    if (r < row + range && r >= row && c < col + range && c >= col) {
        recursion(row, col, range / 2);
        recursion(row, col + (range / 2), range / 2);
        recursion(row + (range / 2), col, range / 2);
        recursion(row + (range / 2), col + (range / 2), range / 2);
    } else {
        cnt += range * range;
    }
}

int main() {
    cin >> N >> r >> c;
    recursion(0, 0, pow(2, N));
    return 0;
}