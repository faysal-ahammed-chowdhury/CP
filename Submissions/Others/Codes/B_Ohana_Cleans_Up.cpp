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
    int n;
    cin >> n;

    unordered_map<string, int> mp;

    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        mp[s]++;
    }

    int mx = 0;

    string str;

    for (auto i : mp)
    {
        if (i.second > mx)
            str = i.first;
        mx = max(i.second, mx);
    }

    cout << mx << endl;
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
