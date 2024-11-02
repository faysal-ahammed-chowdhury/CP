#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int k;
    cin >> k;
    string s, ans = "";
    cin >> s;

    int freq[26] = {};

    for (auto ch : s)
        freq[ch - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0 && freq[i] % k != 0)
        {
            cout << "-1\n";
            return;
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (freq[j] != 0)
            {
                for (int l = 1; l <= freq[j] / k; l++)
                {
                    cout << char(j + 'a');
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
