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
    int a, b, n, tmp, last;
    cin >> a >> b >> n;

    string ans = "";

    tmp = a;
    while (tmp > 0)
    {
        last = tmp % 10;
        tmp /= 10;
        ans += char(last + '0');
    }

    reverse(ans.begin(), ans.end());

    bool flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (((a * 10) + i) % b == 0)
        {
            ans += (i + '0');
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        for (int i = 0; i < n - 1; i++)
        {
            ans += '0';
        }

        cout << ans << "\n";
        return;
    }

    cout << "-1 \n";
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
