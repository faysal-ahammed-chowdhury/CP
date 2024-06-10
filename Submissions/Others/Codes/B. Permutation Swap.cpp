#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        int val; cin >> val;
        if(i != val) {
            v.push_back(abs(val - i));
        }
    }
    int ans = v[0];
    for(auto i : v) {
        ans = __gcd(ans, i);
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