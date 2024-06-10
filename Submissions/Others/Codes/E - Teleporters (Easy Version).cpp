#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n, c; cin >> n >> c;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        pq.push(x + i);
    }
    int ans = 0;
    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if(x > c) break;
        ans++;
        c -= x;
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