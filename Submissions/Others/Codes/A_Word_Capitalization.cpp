#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

string capitalization(string s)
{
    string ans = "";
    int len = s.length();
    ans += (s[0] & ~32);
    ans += (s.substr(1, len - 1));
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    cout << capitalization(s) << endl;
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
