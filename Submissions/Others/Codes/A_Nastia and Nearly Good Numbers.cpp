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
    ll a, b;
    cin >> a >> b;
    ll ab, num1, num2, num3;
    ab = (ll)(a * b);
    num1 = ab;
    num2 = ab + a;
    num3 = num1 + num2;

    if (num2 % ab == 0 && num3 % ab == 0)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << num1 << " " << num2 << " " << num3 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
