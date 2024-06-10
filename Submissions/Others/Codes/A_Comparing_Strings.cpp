#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (s1.length() != s2.length())
    {
        cout << "NO\n";
        return;
    }

    map<char, int> m1, m2;

    for (auto i : s1)
        m1[i]++;
    for (auto i : s2)
        m2[i]++;

    for (auto i : m1)
    {
        if (i.second != m2[i.first])
        {
            cout << "NO\n";
            return;
        }
    }

    int cnt = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            cnt++;
    }

    if (cnt == 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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
