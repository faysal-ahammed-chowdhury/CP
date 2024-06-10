#include <bits/stdc++.h>
using namespace std;

#define FOR(j, n, l) for (int i = j; i < n; i += l)
#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int r, c;
    cin >> r >> c;
    string s[r];
    for (int i = 0; i < r; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (s[i][j] == '.')
            {
                if (i % 2)
                {
                    if (j % 2)
                    {
                        s[i][j] = 'W';
                    }
                    else
                    {
                        s[i][j] = 'B';
                    }
                }
                else
                {
                    if (j % 2)
                    {
                        s[i][j] = 'B';
                    }
                    else
                    {
                        s[i][j] = 'W';
                    }
                }
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        cout << s[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
