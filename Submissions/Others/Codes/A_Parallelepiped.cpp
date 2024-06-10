#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int a, b, c;
    a = sqrt((s1 * s3) / s2);
    b = sqrt((s1 * s2) / s3);
    c = sqrt((s2 * s3) / s1);

    int ans = 4 * (a + b + c);
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
