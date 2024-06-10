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

    int n, m, a, b;
    cin >> n >> m;

    a = min(n, m);
    b = abs(n - m);
    string ans = "";
    for (int i = 0; i < a; i++)
        ans += "BG";

    if (n > m)
    {
        for (int i = 0; i < b; i++)
        {
            ans += "B";
        }
    }
    else if (m > n)
    {
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < b; i++)
        {
            ans += "G";
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
