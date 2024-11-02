#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y, z, sum_x, sum_y, sum_z, i;
    scanf("%d", &n);
    sum_x = 0;
    sum_y = 0;
    sum_z = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }

    if (sum_x == 0 && sum_y == 0 && sum_z == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
