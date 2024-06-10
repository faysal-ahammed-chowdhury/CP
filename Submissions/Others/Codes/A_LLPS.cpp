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
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    for (auto i : s)
        mp[i]++;

    int mx = mp[s[0]];
    char ans = s[0];
    for (auto i : mp)
    {
        if (i.first > ans)
        {
            mx = i.second;
            ans = i.first;
        }
    }

    for (int i = 0; i < mp[ans]; i++)
        cout << ans;
    cout << endl;
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
