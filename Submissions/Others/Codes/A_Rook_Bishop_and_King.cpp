#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

double distance(int x1, int y1, int x2, int y2)
{
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int a, b, c;

    // rook
    if (r1 == r2 && c1 == c2)
        a = 0;
    else if (r1 == r2 || c1 == c2)
        a = 1;
    else
        a = 2;

    // bishop
    if ((r1 + r2) % 2 != (c1 + c2) % 2)
        b = 0;
    else
    {
        if (abs(r1 - r2) == abs(c1 - c2))
            b = 1;
        else
            b = 2;
    }

    // king
    c = max(abs(r1 - r2), abs(c1 - c2));

    cout << a << " " << b << " " << c << "\n";
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
