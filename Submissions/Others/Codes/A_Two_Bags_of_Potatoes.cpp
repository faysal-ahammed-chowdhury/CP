#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int y, k, n;
    cin >> y >> k >> n;

    vector<int> v;

    if (y >= n)
    {
        cout << -1 << endl;
        return;
    }

    int m = k - (y % k);
    int sum = y + m;
    while (sum <= n)
    {
        v.push_back(m);
        m += k;
        sum = y + m;
    }

    if (v.size())
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    cout << -1 << endl;
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
