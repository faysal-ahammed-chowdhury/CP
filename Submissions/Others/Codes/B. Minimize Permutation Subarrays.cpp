#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int idx[n + 1];
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        idx[x] = i;
    }
    if((idx[n] < idx[2] && idx[n] > idx[1]) || (idx[n] > idx[2] && idx[n] < idx[1])) {
        cout << 1 << ' ' << 1 << '\n';
    }
    else {
        int d1 = abs(idx[n] - idx[1]), d2 = abs(idx[n] - idx[2]);
        cout << idx[n] << ' ' << (d1 < d2 ? idx[1] : idx[2]) << '\n';
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