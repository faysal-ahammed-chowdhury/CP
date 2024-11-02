#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    string s1, s2, ans;
    cin >> s1 >> s2;
    ans = "";
    int len = s1.size();
    for (int i = 0; i < len; i++)
    {
        if (s1[i] != s2[i])
            ans += '1';
        else
            ans += '0';
    }

    cout << ans << endl;
}

int main()
{
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
