#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n;
    string s = "";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        s += (val + '0');
    }

    int fivecnt = 0, zerocnt = 0;
    for (auto i : s)
    {
        if (i == '5')
            fivecnt++;
        else if (i == '0')
            zerocnt++;
    }

    if (!zerocnt)
        cout << -1 << endl;
    else if (fivecnt < 9 && zerocnt)
        cout << 0 << endl;
    else if (fivecnt >= 9 && zerocnt)
    {
        int five9cnt = (fivecnt / 9) * 9;
        for (int i = 0; i < five9cnt; i++)
        {
            cout << 5;
        }
        while (zerocnt--)
        {
            cout << 0;
        }
        cout << endl;
    }
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
