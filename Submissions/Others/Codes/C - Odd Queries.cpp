#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n, q; cin >> n >> q;
    long long a[n + 1];
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        long long sum = a[n] - (a[r] - a[l - 1]) + (1LL * (r - l + 1) * k);
        if(sum % 2 == 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
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