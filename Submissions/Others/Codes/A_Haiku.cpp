#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    int c1, c2, c3;
    c1 = 0, c2 = 0, c3 = 0;

    for (auto i : s1)
    {
        if (isVowel(i))
            c1++;
    }
    for (auto i : s2)
    {
        if (isVowel(i))
            c2++;
    }
    for (auto i : s3)
    {
        if (isVowel(i))
            c3++;
    }

    if (c1 == 5 && c2 == 7 && c3 == 5)
        cout << "YES\n";
    else
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
