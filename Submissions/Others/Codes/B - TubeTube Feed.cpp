#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, t; cin >> n >> t;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = -1, enterteinment = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= t && b[i] > enterteinment) {
            ans = i + 1;
            enterteinment = b[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}