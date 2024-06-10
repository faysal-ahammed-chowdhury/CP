#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

bool has_common(int a, int b)
{
    unordered_map<int, int> mp1, mp2;
    while (a > 0)
    {
        mp1[(a % 10)]++;
        a /= 10;
    }

    while (b > 0)
    {
        mp2[(b % 10)]++;
        b /= 10;
    }

    for (auto i : mp1)
    {
        if (mp2[i.first] > 0)
            return true;
    }

    return false;
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int d;
    cin >> d;

    int cnt = 0;
    int lim = sqrt(d + 1);
    for (int i = 1; i <= lim; i++)
    {
        if (d % i == 0)
        {
            cnt += has_common(d, i);
            if (i != d / i)
                cnt += has_common(d, d / i);
        }
    }

    cout << cnt << "\n";
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
