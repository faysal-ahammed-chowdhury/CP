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
    int n, m, val;
    cin >> n >> m;
    int off[n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        for (int j = val; j <= n; j++)
        {
            if (off[j] == 0)
                off[j] = val;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << off[i] << " ";
    cout << endl;
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
