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

    for (int k = 0; k < n; k++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum == arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
            sum += arr[i];
        }
    }
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
