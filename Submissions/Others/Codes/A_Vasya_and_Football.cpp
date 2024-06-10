#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s1, s2;
    cin >> s1 >> s2;
    int n;
    cin >> n;
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    while (n--)
    {
        int min, num;
        char team, card;
        cin >> min >> team >> num >> card;

        if (team == 'h')
        {
            if (mp1.find(num) != mp1.end() && mp1[num] == 2)
                continue;

            if (card == 'y')
            {
                mp1[num]++;
                if (mp1[num] == 2)
                {
                    cout << s1 << ' ' << num << ' ' << min << '\n';
                }
            }
            else
            {
                cout << s1 << ' ' << num << ' ' << min << '\n';
                mp1[num] = 2;
            }
        }
        else
        {
            if (mp2.find(num) != mp2.end() && mp2[num] == 2)
                continue;

            if (card == 'y')
            {
                mp2[num]++;
                if (mp2[num] == 2)
                {
                    cout << s2 << ' ' << num << ' ' << min << '\n';
                }
            }
            else
            {
                cout << s2 << ' ' << num << ' ' << min << '\n';
                mp2[num] = 2;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}