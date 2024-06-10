#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n;
    cin >> n;
    int arr[7];
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }

    int read = 0;
    int ans = 0;
    int i = 0;
    while (read < n)
    {
        read += arr[i];
        ans = i + 1;
        i++;
        if (i == 7)
            i = 0;
    }

    cout << ans << endl;
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
