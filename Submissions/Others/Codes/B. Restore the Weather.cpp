#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, k;
int a[N], b[N];

void solve() {
    cin >> n >> k;
    priority_queue<pair<int, int>> pq1;
    priority_queue<int> pq2;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pq1.push({a[i], i});
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        pq2.push(b[i]);
    }
    map<int, int> mp;
    while(!pq1.empty()) {
        mp[pq1.top().second] = pq2.top();
        pq1.pop();
        pq2.pop();
    }
    for(auto i: mp) {
        cout << i.second << ' ';
    }
    cout << '\n';
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