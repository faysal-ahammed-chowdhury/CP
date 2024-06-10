#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, val, i, j, count;
    cin >> n;
    vector<int> v;
    for (i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }

    v[0] = 1;
    v[n - 1] = 0;
    count = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (v[i] == 0)
            continue;
        for (j = i + 1; j < n; j++)
        {
            if (v[j] == 0)
                count++;
        }
    }

    cout << count << endl;
}
int main()
{
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
