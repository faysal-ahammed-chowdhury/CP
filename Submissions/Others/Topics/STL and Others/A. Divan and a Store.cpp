#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r, k; cin >> n >> l >> r >> k;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        int val; cin >> val;
        if(val >= l && val <= r) {
            v.push_back(val);
        }
    }
    sort(v.begin(), v.end());
    int money = 0, count = 0;
    for(auto i : v) {
        money += i;
        if(money > k) break;
        count++;
    }
    cout << count << '\n';
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