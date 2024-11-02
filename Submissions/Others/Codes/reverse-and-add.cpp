#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll reverse_number(ll num)
{
    ll ans = 0;
    while (num > 0)
    {
        ans = (ans * 10) + num % 10;
        num /= 10;
    }

    return ans;
}

ll solve(ll n, ll &times)
{
    times++;
    ll rev_n = reverse_number(n);
    ll add = rev_n + n;
    if (add == reverse_number(add))
        return add;
    return solve(add, times);
}
int main()
{
    ll test = 1, n, times;
    cin >> test;
    while (test--)
    {
        cin >> n;
        times = 0;
        ll ans = solve(n, times);
        cout << times << " " << ans << endl;
    }
    return 0;
}
