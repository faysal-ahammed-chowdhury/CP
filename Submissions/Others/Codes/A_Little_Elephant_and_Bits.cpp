#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    string s;
    cin >> s;
    bool got = false;

    string ans = "";

    for (auto i : s)
    {
        if (!got && i == '0')
        {
            got = 1;
            continue;
        }
        ans += i;
    }

    if (got)
        cout << ans << endl;
    else
        cout << ans.substr(0, ans.length() - 1) << endl;
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
