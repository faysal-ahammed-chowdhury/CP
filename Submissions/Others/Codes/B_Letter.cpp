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
    // cout << s1 << endl
    //      << s2 << endl;

    map<char, int> m1;
    map<char, int> m2;
    for (auto i : s1)
        m1[i]++;
    for (auto i : s2)
        m2[i]++;

    for (auto i : m2)
    {
        if (i.first == ' ')
            continue;
        if (m1[i.first] < i.second)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
