#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    string s;
    cin >> s;
    set<char> freq;
    for (auto i : s)
        freq.insert(i);

    if (freq.size() % 2 == 1)
        cout << "IGNORE HIM!\n";
    else
        cout << "CHAT WITH HER!\n";
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
