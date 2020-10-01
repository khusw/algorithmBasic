/*
    BOJ 2750 수 정렬하기.
    https://www.acmicpc.net/problem/2750
    보통 온라인 상의 PS 의 경우 초당 1억번의 연산을 수행할 수 있음
    그래서 제한 조건에 따른 초과 여부를 주의할 필요가 있음.

    2750 번 문제는 
    선택 정렬, 버블 정렬 중에서 아무거나 하나 선정해서
    주어진 수를 오름 차순으로 정렬하는 문제로,
    가벼운 문제니 어렵지 않음.
*/

#include <iostream>

using namespace std;

int main() {
    int N, temp;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr[i] = temp;
    }

    // selection sort 를 사용할때.
    int tmp, min, index;
    for (int x = 0; x < N; x++) {
        min = 9999;
        for (int y = x; y < N; y++) {
            if (min > arr[y]) {
                min = arr[y];
                index = y;
            }
        }
        tmp = arr[x];
        arr[x] = arr[index];
        arr[index] = tmp;
    }

    // bubble sort 를 사용할 때.
    /*
        int tmp; // swap 을 위한 변수
        for (int x = 0; x < N; x++) {
            for (int y = x; y < N - 1; y++) {
                if(arr[y] > arr[y + 1]) {
                    tmp = arr[y + 1];
                    arr[y + 1] = arr[y];
                    arr[y] = tmp;
                }
            }
        }
    */

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
    delete[] arr;
}