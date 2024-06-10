#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        else {
            return a.first > b.first;
        }
    }
};

void solve() {
    int n; cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pq.push({x, y});
    }
    long long ans = 0;
    while(!pq.empty()) {
        pair<int, int> x = pq.top();
        pq.pop();
        ans += x.second;
        int cnt = 1;
        while(!pq.empty() && pq.top().first == x.first) {
            if(cnt < x.first) {
                ans += pq.top().second;
                cnt++;
            }
            pq.pop();
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