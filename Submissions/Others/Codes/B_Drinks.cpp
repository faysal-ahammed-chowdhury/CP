#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, sum = 0, val, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> val;
        sum += val;
    }

    double ans;
    ans = sum / double(n);
    printf("%.12lf\n", ans);
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
