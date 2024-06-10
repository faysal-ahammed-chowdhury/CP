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
    int n, n1, n2, ans = 0, step;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < n; i++)
    {
        n1 = s1[i] - '0';
        n2 = s2[i] - '0';
        if (n1 < n2)
            swap(n1, n2);

        step = min(abs(n1 - n2), 9 - n1 + n2 + 1);

        ans += step;
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
