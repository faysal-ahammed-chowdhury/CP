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
    int n, h, m, i, ans, c;
    cin >> n;
    pair<int, int> arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> h >> m;
        arr[i] = {h, m};
    }

    sort(arr, arr + n);

    ans = 1;
    c = 1;
    for (i = 1; i < n; i++)
    {
        if (arr[i].first == arr[i - 1].first && arr[i].second == arr[i - 1].second)
            c++;
        else
            c = 1;

        ans = max(ans, c);
    }

    cout << ans << "\n";
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
