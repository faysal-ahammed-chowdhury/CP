#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ans ^= x;
    }
    if(n & 1) {
        cout << ans << '\n';
    }
    else if(ans == 0) {
        cout << 0 << '\n';
    }
    else {
        cout << -1 << '\n';
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