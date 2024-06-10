#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n, n1, n2;
    cin >> n;
    string s, s1, s2;
    cin >> s;
    s1 = s.substr(0, n);
    s2 = s.substr(n, n);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    bool all_big = true, all_low = true;
    for (int i = 0; i < n; i++)
    {
        n1 = s1[i] - '0';
        n2 = s2[i] - '0';

        // cout << n1 << " " << n2 << endl;

        if (n1 <= n2)
            all_big = false;
        if (n2 <= n1)
            all_low = false;
    }

    if (all_big || all_low)
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
