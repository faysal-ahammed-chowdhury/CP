#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int drinks_mm__person = (k * l) / nl;
    int chun = c * d;
    int salt = p / np;

    int ans = min(salt, min(drinks_mm__person, chun)) / n;
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
