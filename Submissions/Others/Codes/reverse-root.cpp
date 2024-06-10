#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    if (scanf("%lld", &n) == 1)
    {
        solve();
        double ans = sqrt(n);
        printf("%.4lf\n", ans);
    }
    else
        return;
}

int main()
{
    solve();

    return 0;
}
