#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

bool isok(int x, int y)
{
    return x >= 0 && x < 4 && y >= 0 && y < 4 ? true : false;
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s[4];
    cin >> s[0];
    cin >> s[1];
    cin >> s[2];
    cin >> s[3];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (s[i][j] == '.')
                s[i][j] = 0;
            else
                s[i][j] = 1;
        }
    }

    vector<pair<int, int>> v[9];
    v[0] = {{1, 1}, {0, 1}, {0, 0}, {1, 0}};
    v[1] = {{1, 1}, {1, 0}, {2, 0}, {2, 1}};
    v[2] = {{1, 1}, {0, 1}, {0, 2}, {1, 2}};
    v[3] = {{1, 1}, {2, 1}, {2, 2}, {1, 2}};
    v[4] = {{1, 2}, {0, 2}, {0, 3}, {1, 3}};
    v[5] = {{1, 2}, {2, 2}, {1, 3}, {2, 3}};
    v[6] = {{2, 0}, {2, 1}, {3, 0}, {3, 1}};
    v[7] = {{2, 1}, {3, 1}, {2, 2}, {3, 2}};
    v[8] = {{2, 2}, {3, 2}, {2, 3}, {3, 3}};

    for (int i = 0; i < 9; i++)
    {
        int cnt[2] = {0, 0};
        pair<int, int> p1 = v[i][0];
        pair<int, int> p2 = v[i][1];
        pair<int, int> p3 = v[i][2];
        pair<int, int> p4 = v[i][3];

        cnt[s[p1.first][p1.second]]++;
        cnt[s[p2.first][p2.second]]++;
        cnt[s[p3.first][p3.second]]++;
        cnt[s[p4.first][p4.second]]++;

        if (abs(cnt[0] - cnt[1]) == 2 || cnt[0] == 0 || cnt[1] == 0)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
