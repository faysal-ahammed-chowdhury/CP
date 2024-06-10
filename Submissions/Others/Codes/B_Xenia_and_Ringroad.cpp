#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll arr[m];

    for (int i = 0; i < m; i++)
        cin >> arr[i];

    ll t = 0;
    ll curr = 1;

    for (int i = 0; i < m; i++)
    {
        if (arr[i] >= curr)
            t += (arr[i] - curr);
        else
            t += (n - curr + arr[i]);
        curr = arr[i];
    }

    cout << t << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
