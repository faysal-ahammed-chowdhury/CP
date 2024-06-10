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
    int n, i, j, change, cnt1, cnt2, num;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    for (i = 1; i < n; i++)
        arr[i] += arr[i - 1];

    change = 0;

    for (int i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            num = j - i + 1;
            cnt1 = i == 0 ? arr[j] : arr[j] - arr[i - 1];
            cnt2 = num - cnt1;
            change = max(change, cnt2 - cnt1);
        }
    }

    if (change == 0)
        cout << arr[n - 1] - 1 << endl;
    else
        cout << arr[n - 1] + change << endl;
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
