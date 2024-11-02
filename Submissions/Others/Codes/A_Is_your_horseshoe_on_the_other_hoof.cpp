#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

set<int> s;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);

    int ans = 4 - s.size();
    cout << ans << endl;
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
