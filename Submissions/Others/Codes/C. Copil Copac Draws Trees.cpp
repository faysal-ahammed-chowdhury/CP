#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int edges = n - 1;
    vector<pair<int, int>> arr;
    for(int i = 0; i < edges; i++) {
        int u, v; cin >> u >> v;
        arr.push_back({u, v});
    }
    int visited[n + 1];
    fill(visited, visited + n + 1, 0);
    visited[1] = 1;
    set<int> se;
    for(int j = 0; j < 1e5; j++) {
        int first = 1;
        for(auto i: arr) {
            int u = i.first;
            int v = i.second;
            if(visited[u]) {
                visited[v] = 1;
                if(first) {
                    se.insert(u);
                    first = 0;
                }
            }
            else if(visited[v]) {
                visited[u] = 1;
                if(first) {
                    se.insert(v);
                    first = 0;
                }
            }
        }
    }
    cout << (int)se.size() << '\n';
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