/*
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5; // 십만

int W;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W;

    bool check = false;

    int left = 1;  // 과거
    int right = 1; // 현재

    while (left <= right and right <= MAX)
    {
        int G = right * right - left * left; // G 는 현재^2 - 과거^2

        if (G < W)
            right++;
        else if (G == W)
        {
            check = true;
            cout << right << '\n';
            right++;
        }
        else
        {
            left++;
        }
    }

    if (!check)
    {
        cout << -1 << '\n';
    }
    return 0;
}