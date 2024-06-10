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
    string s;
    cin >> s;
    char start = 'n', end = 'n', last;
    int idx = 0, startIdx, endIdx;
    for (auto i : s)
    {
        if (i == 'L' || i == 'R')
        {
            if (start == 'n')
            {
                start = i;
                startIdx = idx;
            }
            end = i;
            endIdx = idx;
        }

        idx++;
    }

    if (start == 'n')
    {
        cout << n << endl;
        return;
    }

    last = start;

    int ans = 0, cnt = 0;

    if (start == 'R')
        ans += startIdx;

    if (end == 'L')
        ans += (n - 1 - endIdx);

    for (auto i : s)
    {
        if (last == i)
        {
            cnt = 0;
            continue;
        }

        if (last == 'L' && i == 'R')
        {
            ans += cnt;
            last = 'R';
            cnt = 0;
            continue;
        }
        else if (last == 'R' && i == 'L')
        {
            if (cnt % 2)
                ans += 1;
            last = 'L';
            cnt = 0;
            continue;
        }

        cnt++;
    }

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
