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
    int k, n, w;
    cin >> k >> n >> w;

    int price = 0;
    for (int i = 1; i <= w; i++)
    {
        price += (i * k);
    }

    if (price > n)
        cout << price - n << endl;
    else
        cout << "0\n";
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
