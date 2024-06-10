#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        a.push_back(val);
    }
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        b.push_back(val);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int done = 0;
    long long ans = 1;
    for(int i = 0; i < n; i++) {
        auto upper = upper_bound(a.begin(), a.end(), b[i]);
        int count = n - (upper - a.begin());
        ans *= max(0, (count - done));
        ans %= MOD;
        done++;
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