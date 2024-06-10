#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int i, n, first, max, min, count, val;
    cin >> n;
    cin >> first;
    max = first;
    min = first;
    count = 0;
    for (i = 1; i < n; i++)
    {
        cin >> val;
        if (val > max)
        {
            count++;
            max = val;
        }
        else if (val < min)
        {
            count++;
            min = val;
        }
    }
    cout << count << endl;
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
