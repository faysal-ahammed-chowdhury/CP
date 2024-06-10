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
    int n, k;
    cin >> n >> k;
    if (k > 26 || k > n || (k == 1 & n != 1))
    {
        cout << -1 << endl;
        return;
    }

    if (k == 1)
    {
        cout << "a\n";
        return;
    }

    string s1 = "";
    string s2 = "";

    for (int i = k; i > 2; i--)
    {
        if (i % k == 0)
        {
            s2 += char(k + 'a' - 1);
        }
        else
        {
            s2 += char((i % k) + 'a' - 1);
        }
    }

    reverse(s2.begin(), s2.end());

    char last = 'b';
    for (int i = 0; i < n - k + 2; i++)
    {
        if (last == 'b')
        {
            s1 += 'a';
            last = 'a';
        }
        else
        {
            s1 += 'b';
            last = 'b';
        }
    }

    cout << s1 + s2 << endl;
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
