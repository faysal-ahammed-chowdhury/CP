#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    long long l, r; cin >> l >> r;
    if(l == r) {
        cout << "0\n";
        return;
    }
    int msb = __lg(l ^ r);
    long long val = 1LL << msb;
    long long ans = (val ^ (val - 1));
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
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}