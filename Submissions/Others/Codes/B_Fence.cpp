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

    for (int i = 1; i < n; i++)
        arr[i] = arr[i - 1] + arr[i];

    int idx = 0, ans = INT32_MAX;
    for (int i = k - 1; i < n; i++)
    {
        if (i == k - 1)
        {
            ans = arr[i];
            idx = i - k + 1;
        }
        else if (arr[i] - arr[i - k] < ans)
        {
            ans = arr[i] - arr[i - k];
            idx = i - k + 1;
        }
    }

    cout << idx + 1 << endl;
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
