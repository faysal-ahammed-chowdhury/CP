#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005, inf = 2e9;
vector<pair<int, int>> g[N];
vector<int> dis(N, inf);
vector<bool> vis(N, false);

void dijkstra(int s, int x) {
  fill(dis.begin(), dis.end(), inf);
  fill(vis.begin(), vis.end(), false);
  dis[s] = x;
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
  pq.push({x, s});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : g[u]) {
      if (w >= d and dis[v] >= w) {
        dis[v] = w;
        pq.push({dis[v], v});
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> m;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  int q; cin >> q;
  while (q--) {
    int a, x, b, y; cin >> a >> x >> b >> y;
    dijkstra(a, x);
    int d = dis[b];

    if (d <= y) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}