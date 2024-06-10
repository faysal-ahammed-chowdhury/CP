#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    long long ans = (1LL * n * n) + (1LL *(n - 4) * 2) + 10;
    cout << ans << '\n';
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