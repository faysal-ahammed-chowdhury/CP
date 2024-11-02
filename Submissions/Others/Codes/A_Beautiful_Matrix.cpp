#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row_i, col_i, i, j, val;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &val);
            if (val)
                row_i = i, col_i = j;
        }
    }

    printf("%d\n", abs(row_i - 2) + abs(col_i - 2));

    return 0;
}
