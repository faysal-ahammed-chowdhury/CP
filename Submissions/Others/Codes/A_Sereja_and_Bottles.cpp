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
    int n, i;
    cin >> n;
    int a[n];
    int b[n];

    unordered_map<int, bool> mp;
    unordered_map<int, bool> remain;
    unordered_map<int, int> freq;

    for (i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        mp[a[i]] = false;
        freq[a[i]]++;
    }

    int cnt = 0;

    for (i = 0; i < n; i++)
    {
        if (remain.find(b[i]) != remain.end() && remain[b[i]])
        {
            remain[b[i]] = false;
            cnt++;
        }
        else if (mp.find(b[i]) != mp.end() && mp[b[i]] == false)
        {
            mp[b[i]] = true;
            if (a[i] != b[i])
            {
                cnt += (freq[b[i]]);
            }
            else
            {
                cnt += (freq[b[i]]) - 1;
                freq[b[i]] = 1;
                remain[b[i]] = true;
            }
        }
    }

    int ans = n - cnt;
    cout << ans << endl;
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
