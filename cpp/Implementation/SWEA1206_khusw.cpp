/*
    SWEA 1206 View
    https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE&&&
*/

#include <cstring>
#include <iostream>

#define endl "\n"

using namespace std;

int cnt, n;
int arr[1001];

int main(int argc, char** argv) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int test_case;

    for (test_case = 1; test_case <= 10; ++test_case) {
        cnt = 0;
        memset(arr, 0, sizeof(arr));

        cin >> n;
        for (int i = 0; i < n; ++i) cin >> arr[i];

        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) continue;

            int left = -1, right = -1;
            // left
            for (int j = i - 1; j >= i - 2; --j) {
                if (arr[j] >= arr[i]) {
                    left = -1;
                    break;
                }
                left = max(left, arr[j]);
            }

            // right
            for (int j = i + 1; j <= i + 2; ++j) {
                if (arr[j] >= arr[i]) {
                    right = -1;
                    break;
                }
                right = max(right, arr[j]);
            }

            if (left == -1 || right == -1) continue;
            cnt = cnt + min(arr[i] - left, arr[i] - right);
        }
        cout << "#" << test_case << " " << cnt << endl;
    }
    return 0;
}
