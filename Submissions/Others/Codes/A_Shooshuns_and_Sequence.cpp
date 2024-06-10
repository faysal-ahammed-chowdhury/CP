#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    k--;
    for (int i = k; i < n; i++)
    {
        if (arr[i] != arr[k])
        {
            cout << -1 << endl;
            return;
        }
    }

    int m = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        if (arr[i] != arr[k])
        {
            break;
        }
        m++;
    }

    cout << k - m << endl;
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
