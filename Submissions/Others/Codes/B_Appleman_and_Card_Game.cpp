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
    int n, k;
    ll ans, m;
    cin >> n >> k;
    string s;
    cin >> s;

    unordered_map<char, int> mp;

    for (auto i : s)
    {
        mp[i]++;
    }

    vector<int> v;

    for (auto i : mp)
    {
        v.push_back(-i.second);
    }

    sort(v.begin(), v.end());

    ans = 0;

    while (k != 0)
    {
        for (auto i : v)
        {
            m = min(-i, k);
            ans += (m * m);
            k -= m;
        }
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
