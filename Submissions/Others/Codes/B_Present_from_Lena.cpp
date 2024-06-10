#include <bits/stdc++.h>
using namespace std;

#define FOR(j, n, l) for (int i = j; i < n; i += l)
#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    int n = 9;
    cin >> n;
    int row = n * 2 + 1;
    int col = row;

    for (int i = 0; i <= n; i++)
    {
        int space = (n - (i % n));
        int j;
        for (j = 0; j < space & i != n; j++)
            cout << "  ";

        for (j = 0; j <= i; j++)
        {
            if (j != 0)
                cout << " ";
            cout << j;
        }

        for (j -= 2; j >= 0; j--)
            cout << " " << j;

        cout << endl;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int space = (n - (i % n));
        int j;
        for (j = 0; j < space; j++)
            cout << "  ";

        for (j = 0; j <= i; j++)
        {
            if (j != 0)
                cout << " ";
            cout << j;
        }

        for (j -= 2; j >= 0; j--)
            cout << " " << j;

        cout << endl;
    }
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
