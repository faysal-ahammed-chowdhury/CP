#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool distinct(int n)
{
    int freq[10] = {0};
    bool distinct = true;
    while (n != 0)
    {
        int last = n % 10;
        if (freq[last] == 0)
        {
            freq[last]++;
        }
        else
        {
            distinct = false;
            break;
        }
        n /= 10;
    }

    return distinct;
}
void solve()
{
    int n;
    cin >> n;

    while (!distinct(++n))
    {
    }

    cout << n << endl;
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
