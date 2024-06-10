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
    int n, a, b, c;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int ans = 0;

    if (b <= 0)
    {
        char last = s[0];
        c = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != last)
            {
                c++;
                last = s[i];
            }
        }
        if (c != 1)
            c = (c / 2) + 1;
        ans = ((a * n) + (b * c));
    }
    else
    {
        ans = ((1 * a) + b) * n;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
