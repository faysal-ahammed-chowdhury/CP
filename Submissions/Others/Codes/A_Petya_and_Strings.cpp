#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

string make_lower(string s)
{
    string ans = "";
    for (auto i : s)
    {
        ans += (i | 32);
    }
    return ans;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    s1 = make_lower(s1);
    s2 = make_lower(s2);

    if (s1 == s2)
        cout << 0 << endl;
    else if (s1 < s2)
        cout << -1 << endl;
    else
        cout << 1 << endl;
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
