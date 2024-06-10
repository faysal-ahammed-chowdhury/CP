#include <bits/stdc++.h>
using namespace std;

#define FOR(j, n, l) for (int i = j; i < n; i += l)
#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    sort(arr, arr + m);
    int ans = INT32_MAX;
    int i = 0;
    while (i + n - 1 < m)
    {
        ans = min(ans, arr[i + n - 1] - arr[i]);
        i++;
    }
    cout << ans << endl;
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
