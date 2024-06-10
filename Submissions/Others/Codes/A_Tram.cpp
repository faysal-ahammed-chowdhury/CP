#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int out, in, now, ans;
void solve()
{
    cin >> out >> in;
    now = now - out + in;
    ans = max(ans, now);
}

int main()
{
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    cout << ans << endl;
    return 0;
}
