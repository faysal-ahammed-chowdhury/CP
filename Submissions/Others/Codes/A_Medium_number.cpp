#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int a, b, c, max, min;
    cin >> a >> b >> c;

    if (a > b && a > c)
    {
        max = a;
        if (b < c)
        {
            min = b;
        }
        else
        {
            min = c;
        }
    }
    else if (b > c && b > a)
    {
        max = b;
        if (a < c)
        {
            min = a;
        }
        else
        {
            min = c;
        }
    }
    else
    {
        max = c;
        if (a < b)
        {
            min = a;
        }
        else
        {
            min = b;
        }
    }

    if (a != max && a != min)
        cout << a << endl;
    if (b != max && b != min)
        cout << b << endl;
    if (c != max && c != min)
        cout << c << endl;
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
