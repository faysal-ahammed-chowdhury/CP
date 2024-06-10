#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<long long> v(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    for(int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
    }
    long long ans = INT_MIN;
    for(int i = 0; i <= k; i++) {
        int start = i * 2;
        int end = n - (k - i);
        long long sum = v[end] - v[start];
        ans = max(ans, sum);
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