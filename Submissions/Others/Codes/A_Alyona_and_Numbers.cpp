#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n, m; cin >> n >> m;
    ll mn, mx;
    mn = min(n, m);
    mx = max(n, m);


    ll cnt = 0;

    for (int i = 1; i <= mn; i++)
    {
        cnt += ((i + mx) / 5) - (i / 5);
    }

    cout << cnt << '\n';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}