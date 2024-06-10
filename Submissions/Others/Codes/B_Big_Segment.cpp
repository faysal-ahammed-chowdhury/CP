#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n, li, ri;
    cin >> n;
    pair<int, int> arr[n];

    int mx = 0, mn = 1000000010;
    for (int i = 0; i < n; i++)
    {
        cin >> li >> ri;
        mn = min(mn, li);
        mx = max(mx, ri);
        arr[i] = {li, ri};
    }

    // cout << mn << " " << mx << endl;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].first <= mn && arr[i].second >= mx)
        {
            cout << i + 1 << endl;
            return;
        }
    }

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
