#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string str, output = "";
    cin >> str;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '-')
        {
            if (str[i + 1] == '.')
            {
                output += '1';
            }
            else
            {
                output += '2';
            }
            i++;
        }

        else if (str[i] == '.')
        {
            output += '0';
        }
    }

    cout << output << endl;
}
int main()
{
    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
