#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

int binary_search(vector<pair<int, int>> &v, int n, int val)
{
    ll low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (val >= v[mid].first && val <= v[mid].second)
            return mid;
        else if (val > v[mid].first)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m, ci, ti, start, end;
    cin >> n >> m;

    vector<pair<int, int>> ans, v;

    for (int i = 0; i < n; i++)
    {
        cin >> ci >> ti;
        v.push_back({ci, ti});
    }

    start = 1;
    end = start + v[0].first * v[0].second - 1;
    ans.push_back({start, end});
    for (int i = 1; i < n; i++)
    {
        start = ans.back().second + 1;
        end = start + v[i].first * v[i].second - 1;
        ans.push_back({start, end});
    }

    while (m--)
    {
        cin >> ti;
        cout << binary_search(ans, n, ti) + 1 << endl;
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