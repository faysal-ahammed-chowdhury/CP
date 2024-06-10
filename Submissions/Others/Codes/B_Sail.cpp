#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

double diff(ll x0, ll y0, ll x, ll y)
{
    double ans = sqrt((abs(x0 - x) * abs(x0 - x)) + (abs(y0 - y) * abs(y0 - y)));
    return ans;
}

void solve()
{
    ll t, x, y, x0, y0;
    cin >> t >> x >> y >> x0 >> y0;
    string s;
    cin >> s;

    ll cnt = 0;
    for (auto i : s)
    {
        if (x == x0 && y == y0)
        {
            cout << cnt << endl;
            return;
        }

        cnt++;
        if (i == 'E') // Right X+1
        {
            ll new_x = x + 1;
            double d1 = diff(x0, y0, x, y);
            double d2 = diff(x0, y0, new_x, y);
            if (d2 < d1)
                x += 1;
        }
        else if (i == 'S') // Down Y-1
        {
            ll new_y = y - 1;
            double d1 = diff(x0, y0, x, y);
            double d2 = diff(x0, y0, x, new_y);
            if (d2 < d1)
                y -= 1;
        }
        else if (i == 'W') // Left X-1
        {
            ll new_x = x - 1;
            double d1 = diff(x0, y0, x, y);
            double d2 = diff(x0, y0, new_x, y);
            if (d2 < d1)
                x -= 1;
        }
        else if (i == 'N') // Up Y+1
        {
            ll new_y = y + 1;
            double d1 = diff(x0, y0, x, y);
            double d2 = diff(x0, y0, x, new_y);
            if (d2 < d1)
                y += 1;
        }
    }

    if (x == x0 && y == y0)
    {
        cout << cnt << endl;
        return;
    }

    cout << -1 << endl;
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
