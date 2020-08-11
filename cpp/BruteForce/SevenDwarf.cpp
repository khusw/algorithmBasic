/*
    BOJ 2309 일곱 난쟁이
    https://www.acmicpc.net/problem/2309

    아홉 개의 줄에 걸쳐서 난쟁이의 키가 주어지고, 
    각 키 값은 100을 넘지 않는 자연수 이며, 각 난쟁이들의 키값은 모두 다르고,
    가능한 정답이 여러개인 경우 아무거나 출력

    출력은 일곱 난쟁이의 키를 오름차순으로 출력
    출력시에 일곱난쟁이를 찾을 수 없는 경우는 없음.

    9개의 수가 주어졌을 때, 7개를 선택해서 합이 100이 되는 경우를 찾으면 되는 문제.
*/

#include <algorithm>
#include <iostream>

using namespace std;

int keys[9];
int sum;
bool checked;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        cin >> keys[i];
        sum += keys[i];
        // 모든 수의 합을 더하고
    }

    for (int x = 0; x < 9; x++) {
        if (checked) break;  // 100 이 된 경우 반복문 탈출
        for (int y = 0; y < 9; y++) {
            if (keys[x] == keys[y]) continue;      // 같은 값일 경우 중복 제거를 위해 continue 사용
            if (sum - keys[x] - keys[y] == 100) {  // 100 이 되는 경우 찾은 경우 이므로,
                checked = true;
                keys[x] = 0;
                keys[y] = 0;
                break;
            }
        }
    }

    sort(keys, keys + 9);

    for (int i = 0; i < 9; i++) {
        if (keys[i] != 0) {
            cout << keys[i] << '\n';
        }
    }

    return 0;
}