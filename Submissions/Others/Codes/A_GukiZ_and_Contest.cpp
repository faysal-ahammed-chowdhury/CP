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
    int sortedarr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sortedarr[i] = arr[i];
    }

    sort(sortedarr, sortedarr + n);
    reverse(sortedarr, sortedarr + n);

    unordered_map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(sortedarr[i]) == mp.end())
        {
            mp[sortedarr[i]] = cnt + 1;
        }
        cnt++;
    }

    for (auto i : arr)
        cout << mp[i] << " ";
    cout << endl;
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
