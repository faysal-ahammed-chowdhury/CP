#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, a, b, c, i, cnt;
    cnt = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (a + b + c >= 2)
            cnt++;
    }
    cout << cnt << endl;
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
