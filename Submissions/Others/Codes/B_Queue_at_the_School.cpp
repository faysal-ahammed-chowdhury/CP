#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    string s;
    int len, n, i, j;
    cin >> len >> n;
    cin >> s;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < len - 1; j++)
        {
            if (s[j] == 'B' && s[j + 1] == 'G')
            {
                swap(s[j], s[j + 1]);
                j++;
            }
        }
    }

    cout << s << endl;
}

int main()
{
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
