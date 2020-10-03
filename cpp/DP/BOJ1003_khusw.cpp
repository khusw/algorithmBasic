#include <iostream>

using namespace std;

int mem[41] = {
    0,
    1,
};

int fib(int num) {
    if (num == 0) {
        return mem[0];
    } else if (num == 1) {
        return mem[1];
    } else if (mem[num] > 0) {
        return mem[num];
    }
    return mem[num] = fib(num - 1) + fib(num - 2);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    int num;
    for (int i = 0; i < T; i++) {
        cin >> num;
        if (num == 0)
            cout << "1 0" << '\n';
        else
            cout << fib(num - 1) << " " << fib(num) << '\n';
    }

    return 0;
}