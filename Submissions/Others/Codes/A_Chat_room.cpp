#include <bits/stdc++.h>
using namespace std;

#define FOR(j, n, l) for (int i = j; i < n; i += l)
#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))
#define str string


void solve()
{
    str s;
    cin >> s;
    int len = s.length();

    if (len < 5)
    {
        cout << "NO\n";
        return;
    }

    int h = -1, e = -1, l1 = -1, l2 = -1, o = -1;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'h')
        {
            h = i;
            break;
        }
    }

    if (h == -1)
    {
        cout << "NO\n";
        return;
    }

    for (int i = h; i < len; i++)
    {
        if (s[i] == 'e')
        {
            e = i;
            break;
        }
    }

    if (e == -1)
    {
        cout << "NO\n";
        return;
    }

    for (int i = e; i < len; i++)
    {
        if (s[i] == 'l')
        {
            l1 = i;
            break;
        }
    }

    if (l1 == -1)
    {
        cout << "NO\n";
        return;
    }

    for (int i = l1 + 1; i < len; i++)
    {
        if (s[i] == 'l')
        {
            l2 = i;
            break;
        }
    }

    if (l2 == -1)
    {
        cout << "NO\n";
        return;
    }

    for (int i = l2; i < len; i++)
    {
        if (s[i] == 'o')
        {
            o = i;
            break;
        }
    }

    if (o == -1)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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
