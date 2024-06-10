#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int arr[1005];

void f(int n)
{
    if (n == 0)
        return;
    swap(arr[n], arr[n - 1]);
    f(--n);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        arr[i - 1] = i;

    f(n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
