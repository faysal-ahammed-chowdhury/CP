#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    vector<string> v;

    string part = "";
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1' || s[i] == '4')
        {
            part += s[i];
            if (s[i] == '1' || i == 0)
            {
                v.push_back(part);
                part = "";
            }
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }

    for (auto i : v)
    {
        if (i == "1" || i == "41" || i == "441")
            continue;
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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
