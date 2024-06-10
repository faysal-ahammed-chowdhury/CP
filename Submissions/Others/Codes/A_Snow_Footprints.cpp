#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;

    int firstright = -1, lastright = -1, firstleft = -1, lastleft = -1;

    int idx = 0;
    for (auto i : s)
    {
        if (i == 'L')
        {
            if (firstleft == -1)
                firstleft = idx;
            lastleft = idx;
        }
        else if (i == 'R')
        {
            if (firstright == -1)
                firstright = idx;
            lastright = idx;
        }

        idx++;
    }

    if (firstright != -1 && firstleft == -1)
    {
        cout << firstright + 1 << " " << lastright + 2 << "\n";
        return;
    }

    if (firstright == -1 && firstleft != -1)
    {
        cout << lastleft + 1 << " " << firstleft << "\n";
        return;
    }

    cout << firstright + 1 << " " << lastright + 1 << "\n";
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
