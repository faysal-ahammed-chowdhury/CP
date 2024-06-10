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
    int n, val;
    cin >> n;
    bool ans = true;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if (val == 25)
        {
            m[25]++;
        }
        else if (val == 50)
        {
            if (m[25] >= 1)
            {
                m[25]--;
                m[50]++;
            }
            else
            {
                ans = false;
            }
        }
        else
        {
            if (m[25] >= 1 && m[50] >= 1)
            {
                m[25]--;
                m[50]--;
                m[100]++;
            }
            else if (m[25] >= 3)
            {
                m[25] = m[25] - 3;
                m[100]++;
            }
            else
            {
                ans = false;
            }
        }
    }

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
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
