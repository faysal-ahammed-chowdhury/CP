#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int min_i = 0;
    int min_j = 1;
    int min = abs(arr[1] - arr[0]);
    for (int i = 0; i < n - 1; i++)
    {
        int d = abs(arr[i] - arr[i + 1]);
        if (d < min)
        {
            min = d;
            min_i = i;
            min_j = i + 1;
        }
    }

    int d = abs(arr[n - 1] - arr[0]);
    if (d < min)
    {
        min = d;
        min_i = n - 1;
        min_j = 0;
    }

    cout << ++min_i << " " << ++min_j << endl;
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
