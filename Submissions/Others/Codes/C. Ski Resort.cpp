#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v;
    int consecutive = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= q) consecutive++;
        else {
            v.push_back(consecutive);
            consecutive = 0;
        }
    }
    v.push_back(consecutive);
    long long ans = 0;
    for(auto i: v) {
        if(i >= k) {
            for(int j = k; j <= i; j++) {
                int val = max(0, i - j + 1);
                ans += val;
            }
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