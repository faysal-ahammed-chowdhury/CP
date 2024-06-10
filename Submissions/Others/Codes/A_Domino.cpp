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
    int n, l, r, ls, rs;
    cin >> n;
    ls = 0, rs = 0;
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        ls += l;
        rs += r;
        if (l % 2 != r % 2)
            ok = true;
    }

    // cout << ls << " " << rs << endl;

    if (ls % 2 == 0 && rs % 2 == 0)
        cout << 0 << endl;
    else if ((ls + rs) % 2 == 1)
        cout << -1 << endl;
    else if (ok)
        cout << 1 << endl;
    else
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
