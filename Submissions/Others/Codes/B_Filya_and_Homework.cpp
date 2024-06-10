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
    int n;
    cin >> n;
    int arr[n];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int last = arr[0];
    v.push_back(last);

    for (int i = 1; i < n; i++)
    {
        if (last != arr[i])
        {
            v.push_back(arr[i]);
            last = arr[i];
        }
    }

    int sz = size_t(v.size());
    if (sz > 3)
    {
        cout << "NO\n";
        return;
    }

    bool ans = true;
    if (sz == 3)
        ans = v[1] - v[0] == v[2] - v[1];

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
