#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    string s;
    cin >> s;
    int flag = 0;
    for (auto i : s)
    {
        if (i == 'H' || i == 'Q' || i == '9')
        {
            cout << "YES\n";
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        cout << "NO\n";
    }
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
