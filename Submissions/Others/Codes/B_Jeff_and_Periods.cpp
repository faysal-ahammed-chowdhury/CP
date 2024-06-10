#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n, val;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        m[val].push_back(i);
    }

    vector<pair<int, int>> v;

    for (auto i : m)
    {
        int sz = i.second.size();
        if (sz == 1)
        {
            v.push_back({i.first, 0});
            continue;
        }

        int diff = i.second[1] - i.second[0];
        bool flag = 1;
        for (int j = 0; j < sz - 1; j++)
        {
            if (abs(i.second[j] - i.second[j + 1]) != diff)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            v.push_back({i.first, diff});
    }

    cout << v.size() << endl;
    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
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
