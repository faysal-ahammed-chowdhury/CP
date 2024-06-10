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
    int n, up = 0, sit = 0;
    cin >> n;
    string s;
    cin >> s;
    for (auto i : s)
    {
        if (i == 'x')
            sit++;
        else
            up++;
    }

    int diff = abs(n / 2 - up);

    if (up > sit)
    {
        int cnt = 0;

        for (auto i = 0; i < s.size(); i++)
        {
            if (cnt < diff && s[i] == 'X')
            {
                s[i] = 'x';
                cnt++;
            }
        }
    }
    else
    {
        int cnt = 0;

        for (auto i = 0; i < s.size(); i++)
        {
            if (cnt < diff && s[i] == 'x')
            {
                s[i] = 'X';
                cnt++;
            }
        }
    }

    cout << diff << endl;
    cout << s << endl;
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
