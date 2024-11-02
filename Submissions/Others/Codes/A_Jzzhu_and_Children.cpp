#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, m, i, maxIndex, val, ans;
    cin >> n >> m;

    vector<pair<int, int>> v;
    for (i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back({i + 1, val});
    }

    while (v.size())
    {
        int first = v[0].first;
        int second = v[0].second;

        v.erase(v.begin());
        if (second > m)
            v.push_back({first, second - m});

        ans = first;
    }

    cout << ans << endl;
}

int main()
{
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
