#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    string s;
    cin >> s;
    int len = s.length();

    string ans = "";

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'W' && i + 2 < len)
        {
            if (s[i + 1] == 'U' && s[i + 2] == 'B')
            {
                if (ans != "" && ans.back() != ' ')
                    ans += " ";
                i += 2;
                continue;
            }
        }
        ans += s[i];
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
