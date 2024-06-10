#include <bits/stdc++.h>
using namespace std;

#define FOR(j, n, l) for (int i = j; i < n; i += l)
#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ll d = arr[n - 1] - arr[0];
    ll w = 0;
    ll lc = 0, hc = 0;
    int i = 0;
    while (arr[i] == arr[0])
    {
        lc++;
        i++;
    }
    i = n - 1;
    while (arr[i] == arr[n - 1])
    {
        hc++;
        i--;
    }
    w = lc * hc;
    if (arr[0] == arr[n - 1])
    {
        w = ((n) * (n - 1)) / 2;
    }
    cout << d << " " << w << endl;
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
