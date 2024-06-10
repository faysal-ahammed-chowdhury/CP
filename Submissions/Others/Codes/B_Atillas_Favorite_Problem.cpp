#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int max = 'a';
    for (int i = 0; i < n; i++)
    {
        if (str[i] > max)
            max = str[i];
    }

    cout << max - 96 << endl;
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
