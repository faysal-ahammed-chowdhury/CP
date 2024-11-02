#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

vector<pair<int, int>> v;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    int cnt = 0;

    for (auto i : v)
    {
        int x = i.first;
        int y = i.second;

        int match = 0;
        for (auto p : v)
        {
            int newx = p.first;
            int newy = p.second;

            if (newx > x && newy == y)
            {
                match++;
                break;
            }
        }
        for (auto p : v)
        {
            int newx = p.first;
            int newy = p.second;

            if (newx < x && newy == y)
            {
                match++;
                break;
            }
        }
        for (auto p : v)
        {
            int newx = p.first;
            int newy = p.second;

            if (newx == x && newy > y)
            {
                match++;
                break;
            }
        }
        for (auto p : v)
        {
            int newx = p.first;
            int newy = p.second;

            if (newx == x && newy < y)
            {
                match++;
                break;
            }
        }

        if (match == 4)
            cnt++;
    }

    cout << cnt << endl;
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
