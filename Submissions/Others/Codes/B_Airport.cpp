#include <bits/stdc++.h>
using namespace std;

#define FOR(j, n, l) for (int i = j; i < n; i += l)
#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n, m, val;
    cin >> n >> m;
    vector<int> v1, v2;
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        v1.push_back(val);
        v2.push_back(val);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int max_ans = 0;
    int min_ans = 0;

    for (int i = 0; i < n; i++)
    {
        max_ans += (v1[v1.size() - 1]);
        v1[v1.size() - 1] -= 1;

        min_ans += (v2[0]);
        v2[0] -= 1;
        if (v2[0] == 0)
            v2[0] = 10001;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
    }

    cout << max_ans << " " << min_ans << endl;
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
