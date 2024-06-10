#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void solve()
{
    int n = 5;
    int arr[10][10];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int a[15] = {1, 2, 3, 4, 5};

    int ans = 0;

    do
    {
        int happiness = 0;
        happiness += arr[a[0]][a[1]];
        happiness += arr[a[1]][a[0]];

        happiness += arr[a[2]][a[3]];
        happiness += arr[a[3]][a[2]];

        happiness += arr[a[1]][a[2]];
        happiness += arr[a[2]][a[1]];

        happiness += arr[a[3]][a[4]];
        happiness += arr[a[4]][a[3]];

        happiness += arr[a[2]][a[3]];
        happiness += arr[a[3]][a[2]];

        happiness += arr[a[3]][a[4]];
        happiness += arr[a[4]][a[3]];

        ans = max(ans, happiness);

    } while (next_permutation(a, a + n));

    cout << ans << endl;
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
