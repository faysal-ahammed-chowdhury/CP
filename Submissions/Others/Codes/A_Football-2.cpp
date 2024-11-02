#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
// Codeforces Beta Round #77 (Div. 2 Only)
void solve()
{
    string s;
    cin >> s;
    int cnt = 1;
    int ans = 0;

    int len = s.length();

    char last = s[0];
    for (int i = 1; i < len; i++)
    {
        if (last == s[i])
            cnt++;
        else
            cnt = 1;

        last = s[i];
        ans = max(ans, cnt);
    }

    if (ans >= 7)
        cout << "YES\n";
    else
        cout << "NO\n";
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
