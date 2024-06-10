#include <bits/stdc++.h>
using namespace std;

#define FOR(j, n, l) for (int i = j; i < n; i += l)
#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int s, n, val, val2;
    cin >> s >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        cin >> val >> val2;
        v.push_back({val, val2});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        int first = v[i].first;
        int sec = v[i].second;

        // cout << first << ", " << sec << endl;

        if (s <= first)
        {
            cout << "NO\n";
            return;
        }

        s += sec;
    }

    cout
        << "YES\n";
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
