#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

string upper(string s)
{
    string ans = "";
    for (auto i : s)
    {
        ans += (i & ~32);
    }

    return ans;
}

string lower(string s)
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
    string s;
    cin >> s;
    int len = s.length(), i;
    int lowerCount = 0, upperCount = 0;
    for (i = 0; i < len; i++)
    {
        if (islower(s[i]))
            lowerCount++;
        else
            upperCount++;
    }

    if (upperCount > lowerCount)
        cout << upper(s) << endl;
    else
        cout << lower(s) << endl;
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
