#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        int msb = __lg(x);
        mp[msb]++;
    }
    long long ans = 0;
    for(auto i: mp) {
        ans += ((1LL * i.second * (i.second - 1)) / 2);
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