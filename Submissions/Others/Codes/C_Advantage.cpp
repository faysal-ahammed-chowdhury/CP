#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, val, max, second_max, max_index, second_max_index, i;
    cin >> n;
    vector<int> v;

    max_index = -1;
    second_max_index = -1;

    for (i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }

    vector<int> v2 = v;

    sort(v2.begin(), v2.begin() + n);
    max_index = n - 1;
    second_max_index = n - 2;
    max = v2[max_index];
    second_max = v2[second_max_index];

    for (i = 0; i < n; i++)
    {
        if (v[i] == max)
            cout << v[i] - second_max;
        else
            cout << v[i] - max;

        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
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
