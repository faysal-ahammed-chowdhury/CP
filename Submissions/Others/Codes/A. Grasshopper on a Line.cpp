#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int x, k; cin >> x >> k;
    if(x % k == 0) {
        cout << 2 << '\n';
        cout << x - 1 << ' ' << 1 << '\n';
    }
    else {
        cout << 1 << '\n';
        cout << x << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}