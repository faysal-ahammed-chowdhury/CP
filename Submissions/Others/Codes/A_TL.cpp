#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n, m, a, b, c;
    cin >> n >> m;
    int arr[n];
    int arr2[m];

    a = INT32_MAX;
    b = 0;
    c = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        a = min(a, arr[i]);
        b = max(b, arr[i]);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
        c = min(c, arr2[i]);
    }

    if (b < c && (a * 2 < c))
    {
        cout << max(2 * a, b) << endl;
    }
    else
    {
        cout << -1 << endl;
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
