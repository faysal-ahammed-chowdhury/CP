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

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    vector<int> v1, v2;

    for (auto i : mp)
    {
        v1.push_back(i.first);
    }

    for (auto i : mp)
    {
        if (i.second > 1 && i.first != v1.back())
        {
            v2.push_back(i.first);
        }
    }

    reverse(v2.begin(), v2.end());

    int sz = size_t(v1.size() + v2.size());
    cout << sz << endl;

    for (auto i : v1)
        cout << i << " ";
    for (auto i : v2)
        cout << i << " ";

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
