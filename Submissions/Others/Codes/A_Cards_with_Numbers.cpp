#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n, val;
    cin >> n;
    n *= 2;

    unordered_map<ll, vector<int>> m;
    unordered_map<ll, ll> m2;
    for (ll i = 0; i < n; i++)
    {
        cin >> val;
        m[val].push_back(i + 1);
        m2[val]++;
    }

    for (auto i : m2)
    {
        if (i.second % 2 != 0)
        {
            cout << "-1\n";
            return;
        }
    }

    for (auto i : m)
    {
        for (int j = 0; j < i.second.size(); j += 2)
        {
            cout << i.second[j] << " " << i.second[j + 1] << endl;
        }
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
