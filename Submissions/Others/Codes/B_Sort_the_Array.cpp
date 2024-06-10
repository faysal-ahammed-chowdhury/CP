#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, i, left, right;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    left = -1;
    right = -1;

    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            left = i + 1;
            break;
        }
    }

    for (i = n - 1; i > 0; i--)
    {
        if (arr[i] < arr[i - 1])
        {
            right = i + 1;
            break;
        }
    }

    reverse(arr + left - 1, arr + right);

    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cout << "no\n";
            return;
        }
    }

    cout << "yes\n";
    cout << abs(left) << " " << abs(right) << endl;
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
