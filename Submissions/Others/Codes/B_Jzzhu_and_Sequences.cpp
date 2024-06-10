#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

ll modulo(ll x, ll y)
{
    ll res = x % y;
    while (res < 0)
    {
        res += y;
    }
    return res;
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll x, y, z, n, ans;
    cin >> x >> y >> n;

    z = y - x;

    if (((n - 1) / 3) % 2 == 0)
    {
        if (n % 3 == 0)
            ans = z;
        else if (n % 3 == 1)
            ans = x;
        else if (n % 3 == 2)
            ans = y;
    }
    else
    {
        if (n % 3 == 0)
            ans = -z;
        else if (n % 3 == 1)
            ans = -x;
        else if (n % 3 == 2)
            ans = -y;
    }

    ans = modulo(ans, mod);

    cout << ans << "\n";
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
