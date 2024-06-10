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
    int n, m, d, i, j, dis, dis_sum, val;
    cin >> n >> m >> d;

    vector<int> v;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> val;
            v.pb(val);
        }
    }

    sort(v.begin(), v.end());

    int len = v.size();
    int mid = v[(len - 1) / 2];

    dis_sum = 0;
    for (i = 0; i < len; i++)
    {
        dis = abs(v[i] - mid);
        dis_sum += dis;
    }

    if (dis_sum % d == 0)
    {
        int ans = dis_sum / d;
        cout << ans << "\n";
        return;
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
