#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int k;
    cin >> k;
    int arr[12];
    for (int i = 0; i < 12; i++)
        cin >> arr[i];

    if (k == 0)
    {
        cout << 0 << endl;
        return;
    }

    sort(arr, arr + 12);

    int sum = 0, cnt = 0;
    for (int i = 11; i >= 0; i--)
    {
        sum += arr[i];
        cnt++;
        if (sum >= k)
        {
            cout << cnt << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
