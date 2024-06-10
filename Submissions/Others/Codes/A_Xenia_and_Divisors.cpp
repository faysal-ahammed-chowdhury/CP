#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int grp = n / 3;
    vector<int> v[grp];

    for (int i = 0; i < n; i++)
        v[i % grp].push_back(arr[i]);

    int cnt = 0;

    vector<int> ans[grp];

    for (int i = 0; i < grp; i++)
    {
        int a = v[i][0];
        int b = v[i][1];
        int c = v[i][2];

        if (c > b && b > a && c % b == 0 && b % a == 0)
        {
            cnt++;
            ans[i].push_back(a);
            ans[i].push_back(b);
            ans[i].push_back(c);
        }
    }

    if (cnt == grp)
    {
        for (int i = 0; i < grp; i++)
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
        return;
    }

    cout << -1 << endl;
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
