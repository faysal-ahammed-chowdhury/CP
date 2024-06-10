#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

int nod(int n)
{
    unordered_map<int, int> m;
    while (n % 2 == 0)
    {
        m[2]++;
        n /= 2;
    }

    int limit = sqrt(n + 1);
    for (int i = 3; i <= limit; i += 2)
    {
        while (n % i == 0)
        {
            m[i]++;
            n /= i;
        }
    }

    if (n > 2)
        m[n]++;

    int ans = 1;
    for (auto i : m)
    {
        ans *= (i.second + 1);
    }

    return ans;
}

int d(int a, int b, int c)
{
    int mul = a * b * c;

    return nod(mul);
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a, b, c, ans;
    cin >> a >> b >> c;
    ans = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                ans += d(i, j, k);
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
