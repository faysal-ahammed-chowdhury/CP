#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, sum, i, val, cnt;
    cin >> n;
    sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> val;
        sum += val;
    }
    n++;
    cnt = 0;
    if ((sum + 1) % n != 1)
        cnt++;
    if ((sum + 2) % n != 1)
        cnt++;
    if ((sum + 3) % n != 1)
        cnt++;
    if ((sum + 4) % n != 1)
        cnt++;
    if ((sum + 5) % n != 1)
        cnt++;

    cout << cnt << endl;
}

int main()
{
    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
