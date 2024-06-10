#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, m, cnt;
    cin >> n >> m;
    cnt = 0;

    for (int a = 0; a < 1000; a++)
    {
        for (int b = 0; b < 1000; b++)
        {
            bool first = (a * a) + b == n;
            bool sec = a + (b * b) == m;
            if (first && sec)
                cnt++;
        }
    }

    cout << cnt << endl;
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
