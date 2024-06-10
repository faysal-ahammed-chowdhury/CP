#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 5005, inf = 1e9;
vector<pii> g[N];
int n, m;
set<int> se;

void dijkstra(int u, vector<int> &vis) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, u});
  while (!pq.empty()) {
    int d = pq.top().first;
    int selected_node = pq.top().second;
    pq.pop();
    vis[selected_node]++;
    if (vis[selected_node] > 2) continue;
    for (auto [v, w] : g[selected_node]) {
      pq.push({w + d, v});
      if (v == n) se.insert(w + d);
    }
  }
}

int cs;
void solve() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector<int> vis(n + 1, 0);
  se.clear();
  dijkstra(1, vis);
  se.erase(se.begin());
  int ans = *se.begin();
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}