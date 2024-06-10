#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n;
    int val;
    cin >> val;

    priority_queue<int> pq;
    for (int i = 1; i < n; i++)
    {
        cin >> m;
        pq.push(m);
    }

    int cnt = 0;

    while (val <= pq.top())
    {
        m = pq.top();
        pq.pop();
        val++;
        pq.push(m - 1);

        cnt++;
    }

    cout << cnt << endl;
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
