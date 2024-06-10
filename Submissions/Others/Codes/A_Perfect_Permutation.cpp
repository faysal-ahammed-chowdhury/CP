#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin >> n;

    // Ppi = i and pi ≠ i
    int arr[n + 1] = {};
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    if (n % 2 == 1)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << arr[i + 1] << " ";
        }
        else
        {
            cout << arr[i - 1] << " ";
        }
    }
    cout << endl;
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
