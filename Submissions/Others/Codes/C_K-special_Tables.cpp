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
    int n, k;
    cin >> n >> k;
    int arr[n + 1][n + 1];

    int right = n - k;
    int val = (n * n) - right;

    for (int i = 1; i <= n; i++)
    {
        arr[i][k] = val;
        for (int j = k + 1; j <= n; j++)
        {
            arr[i][j] = arr[i][j - 1] + 1;
        }
        val -= (right + 1);
    }

    val = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            arr[i][j] = val;
            val++;
        }
    }

    val = 0;
    for (int i = 1; i <= n; i++)
    {
        val += arr[i][k];
    }

    cout << val << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
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
