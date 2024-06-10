#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    k = min(k, 30);
    int ans = (1 << k);
    cout << min(ans, n + 1) << '\n';
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