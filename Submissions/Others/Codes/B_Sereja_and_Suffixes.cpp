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
    int n, m, i, j, val;
    cin >> n >> m;
    unordered_map<int, int> mp;
    ll arr[n];
    int arr2[n];

    for (i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    for (i = 0, j = n - 1; i < n; i++, j--)
    {
        val = arr2[j];
        mp[val]++;
        if (i == 0)
        {
            arr[i] = 1;
            continue;
        }

        if (mp[val] == 1)
            arr[i] = arr[i - 1] + 1;
        else
            arr[i] = arr[i - 1];
    }

    reverse(arr, arr + n);

    // for (i = 0; i < n; i++)
    //     cout << arr[i] << endl;

    while (m--)
    {
        cin >> val;
        val--;
        cout << arr[val] << endl;
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
