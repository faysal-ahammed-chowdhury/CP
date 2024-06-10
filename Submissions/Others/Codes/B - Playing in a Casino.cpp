#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    int a[m][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[j][i];
        }
    }
    long long ans = 0;
    for(int i = 0; i < m; i++) {
        sort(a[i], a[i] + n);
        long long sum = 0;
        for(int j = 0; j < n; j++) {
            ans += (1LL * a[i][j] * j) - sum;
            sum += a[i][j];
        }
    }
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