#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n, v, s;
    cin >> n;
    s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        s += (v);
    }

    if (s % n == 0)
    {
        cout << n << endl;
    }
    else
    {
        cout << n - 1 << endl;
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
