#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans;
    if (k <= (n + 1) / 2)
        ans = 2 * (k - 1) + 1;
    else if (n % 2 == 0)
        ans = 2 * k - n;
    else
        ans = 2 * k - n - 1;
    cout << ans << endl;
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
