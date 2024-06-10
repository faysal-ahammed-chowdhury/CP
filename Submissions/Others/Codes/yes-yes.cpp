#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string main = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
    string str;
    cin >> str;

    int start_index = -1;
    for (int i = 0; i < main.length(); i++)
    {
        if (str[0] == main[i])
        {
            start_index = i;
            break;
        }
    }

    if (start_index == -1)
    {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != main[start_index + i])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
int main()
{
    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
