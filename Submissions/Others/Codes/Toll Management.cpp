#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10000 + 9;
const ll inf = 1e12; 
vector<array<int, 2>> g[N], gT[N];
int n, m;

auto dijkstra(int s) {
  vector<ll> dis(n + 1, inf);
  vector<bool> vis(n + 1, false);
  dis[s] = 0;
  priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : g[u]) {
      if (dis[v] > d + w) {
        dis[v] = d + w;
        pq.push({dis[v], v});
      }
    }
  }
  return dis;
}

auto dijkstra2(int s) {
  vector<ll> dis(n + 1, inf);
  vector<bool> vis(n + 1, false);
  dis[s] = 0;
  priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : gT[u]) {
      if (dis[v] > d + w) {
        dis[v] = d + w;
        pq.push({dis[v], v});
      }
    }
  }
  return dis;
}

int cs;
void solve() {
  int s, t, p; cin >> n >> m >> s >> t >> p;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    gT[i].clear();
  }
  vector<array<int, 3>> edges;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    gT[v].push_back({u, w});
    edges.push_back({u, v, w});
  }
  auto dis1 = dijkstra(s);
  auto dis2 = dijkstra2(t);
  int ans = -1;
  for (auto [u, v, w] : edges) {
    ll d = dis1[u] + dis2[v] + w;
    if (d <= p) ans = max(ans, w);
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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