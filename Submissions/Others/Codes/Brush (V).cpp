#include <bits/stdc++.h>
using namespace std;

const int N = 105, inf = 1e9;
vector<array<int, 2>> g[N];
int n, m, dis[N];

void dijkstra(int u) {
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
  pq.push({0, u});
  dis[u] = 0;
  while (!pq.empty()) {
    auto [d, selected_node] = pq.top();
    pq.pop();
    for (auto [v, w] : g[selected_node]) {
      if (dis[v] > d + w) {
        dis[v] = d + w;
        pq.push({dis[v], v});
      }
    }
  }
}

int cs;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dis[i] = inf;
  }

  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dijkstra(1);
  cout << "Case " << ++cs << ": ";
  (dis[n] == inf ? cout << "Impossible\n" : cout << dis[n] << '\n');
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}