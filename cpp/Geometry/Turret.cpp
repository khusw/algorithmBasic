#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x1, y1, r1, x2, y2, r2, T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double s = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) {
                printf("-1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if (abs(r1 - r2) < s && s < (r1 + r2)) {
            printf("2\n");
        }
        else if (abs(r1 - r2) == s || s == (r2 + r1)) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}