#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int l1, l2, l3;
    l1 = s1.length();
    l2 = s2.length();
    l3 = s3.length();

    if (l1 + l2 == l3)
    {
        int freq[26] = {};
        int freq2[26] = {};
        for (auto i : s1)
            freq[i - 'A']++;
        for (auto i : s2)
            freq[i - 'A']++;
        for (auto i : s3)
            freq2[i - 'A']++;

        int flag = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != freq2[i])
            {
                cout << "NO\n";
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << "YES\n";
        }
    }
    else
    {
        cout << "NO\n";
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
