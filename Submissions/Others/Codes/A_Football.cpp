#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n;
    cin >> n;
    string s;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        m[s]++;
    }

    string winner;
    int g = 0;
    for (auto i : m)
    {
        if (i.second > g)
        {
            winner = i.first;
            g = i.second;
        }
    }

    cout << winner << endl;
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
