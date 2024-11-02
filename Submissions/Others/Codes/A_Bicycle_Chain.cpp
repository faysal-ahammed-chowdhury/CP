#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, m;
    map<int, int> mp;

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int div = arr2[j] / arr[i];
            if (arr[i] * div == arr2[j])
                mp[div]++;
        }
    }

    int div = 0;
    for (auto i : mp)
        if (i.first > div)
            div = i.first;
    cout << mp[div] << endl;
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
