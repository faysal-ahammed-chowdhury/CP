#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    ll n, i, m, a, b, c;
    cin >> n;
    ll arr[n];
    ll index[n + 1];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        index[arr[i]] = i + 1;
    }

    b = 0, c = 0;
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> a;
        b += index[a];
        c += n + 1 - index[a];
    }

    cout << b << " " << c << endl;
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
