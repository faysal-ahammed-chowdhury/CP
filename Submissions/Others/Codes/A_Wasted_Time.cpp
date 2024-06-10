#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

double distance(int x1, int y1, int x2, int y2)
{
    double ans = sqrt((abs(x1 - x2) * abs(x1 - x2)) + (abs(y1 - y2) * abs(y1 - y2)));
    return ans;
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k, x, y;
    cin >> n >> k;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        arr[i] = {x, y};
    }

    double d = 0;
    for (int i = 0; i < n - 1; i++)
    {
        d += distance(arr[i].first, arr[i].second, arr[i + 1].first, arr[i + 1].second);
    }

    double ans = (d / 50.0) * k;
    printf("%0.8lf\n", ans);
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
