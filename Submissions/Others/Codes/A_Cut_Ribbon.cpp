#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, a, b, c, d, e;
    cin >> n >> a >> b >> c;
    int arr[] = {a, b, c};
    sort(arr, arr + 3);
    a = arr[0];
    b = arr[1];
    c = arr[2];

    int ans = 0;

    for (int i = 0; i <= 4000; i++)
    {
        for (int j = 0; j <= 4000; j++)
        {
            e = ((i * a) + (j * b));
            d = (n - e);
            if (d == 0 && d >= 0)
                ans = max(ans, i + j);
            else if (d % c == 0 && d >= 0)
            {
                e = (i + j + (d / c));
                ans = max(ans, e);
            }
        }
    }

    cout << ans << endl;
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
