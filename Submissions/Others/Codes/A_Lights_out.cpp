#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    bool output[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            output[i][j] = 1;
        }
    }

    int val;

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cin >> val;
            if (val % 2 != 0)
            {
                // 1
                output[row][col] = !output[row][col];

                if (row - 1 >= 0)
                {
                    output[row - 1][col] = !output[row - 1][col];
                }
                if (row + 1 <= 2)
                {
                    output[row + 1][col] = !output[row + 1][col];
                }

                if (col - 1 >= 0)
                {
                    output[row][col - 1] = !output[row][col - 1];
                }
                if (col + 1 <= 2)
                {
                    output[row][col + 1] = !output[row][col + 1];
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << output[i][j];
        }
        cout << endl;
    }
}
int main()
{
    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
