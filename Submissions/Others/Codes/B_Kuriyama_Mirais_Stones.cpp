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
    int n, m, i, a, b, c;
    cin >> n;
    ll arr[n];
    ll sorted_arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }

    sort(sorted_arr, sorted_arr + n);

    for (i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
        sorted_arr[i] += sorted_arr[i - 1];
    }

    m;
    cin >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        b--, c--;
        if (a == 1)
        {
            if (b == 0)
                cout << arr[c] << endl;
            else
                cout << arr[c] - arr[b - 1] << endl;
        }
        else
        {
            if (b == 0)
                cout << sorted_arr[c] << endl;
            else
                cout << sorted_arr[c] - sorted_arr[b - 1] << endl;
        }
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
