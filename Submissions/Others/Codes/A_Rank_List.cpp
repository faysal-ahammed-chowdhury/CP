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
    int n, k, s, p;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> p;
        v.push_back({-s, p});
    }

    sort(v.begin(), v.end());

    // for (auto i : v)
    // {
    //     cout << -i.first << " " << i.second << endl;
    // }

    // cout << (v[0] == v[1]);

    int cnt = 0;

    for (int i = k - 2; i >= 0; i--)
        if (v[k - 1] == v[i])
            cnt++;

    for (int i = k; i < n; i++)
        if (v[k - 1] == v[i])
            cnt++;

    cout << ++cnt << endl;
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
