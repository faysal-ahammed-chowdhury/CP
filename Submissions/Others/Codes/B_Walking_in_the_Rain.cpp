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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 10000;
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, max(arr[i], arr[i + 1]));
    }

    ans = min(arr[0], ans);
    ans = min(arr[n - 1], ans);

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
