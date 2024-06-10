#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y, h; cin >> x >> y >> h;
    int ans = 1 * x;
    ans += ((h - 1) * y);
    cout << ans << '\n';

    return 0;
}