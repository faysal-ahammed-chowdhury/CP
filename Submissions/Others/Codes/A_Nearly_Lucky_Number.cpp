#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    string s;
    cin >> s;
    int cnt = 0;

    for (auto i : s)
    {
        if (i == '4' || i == '7')
            cnt++;
    }

    if (cnt == 4 || cnt == 7)
        cout << "YES\n";
    else
        cout << "NO\n";
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
