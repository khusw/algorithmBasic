#include <iostream>

using namespace std;

int fib(int n) {
    if (n <= 1)
        return n;
    int F, F1, F2;
    F1 = 0;
    F2 = 1;
    for (int i = 2; i < n; i++) {
        F = F1 + F2;
        F1 = F2;
        F2 = F;
    }
    return F;
}

int Fib(int n) {
    if (n <= 1)
        return n;
    else
        Fib(n - 1) + Fib(n - 2);
}

int fibo(int n) {
    int data[100];
    if (n <= 2)
        return 1;

    if (data[n] != 0) {
        return data[n];
    } else {
        data[n] = fibo(n - 1) + fibo(n - 2);
        return data[n];
    }
}

int main() {
    int n;
    cin >> n;
    int result = fib(n);
    cout << result << '\n';
}