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

    int cnt = 0;

    set<pair<int, int>> s;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double ans = sqrt(((i * i) + (j * j)));
            bool ok = ((int)ans * ans) == (i * i) + (j * j);
            if (ok && ans <= n)
            {
                if (i < j)
                    s.insert({i, j});
                else
                    s.insert({j, i});
            }
        }
    }

    cout << s.size() << endl;
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
