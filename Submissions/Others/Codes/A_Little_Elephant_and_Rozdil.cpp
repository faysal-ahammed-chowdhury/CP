#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, val;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back({val, i + 1});
    }

    sort(v.begin(), v.end());
    if (n > 1 && v[0].first == v[1].first)
        cout << "Still Rozdil";
    else
        cout << v[0].second << endl;
}

int main()
{
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
