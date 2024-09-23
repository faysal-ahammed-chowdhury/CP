#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10000 + 9;
const ll inf = 1e12;
vector<array<int, 3>> g[N];
int n, m, k, dd;

auto dijkstra(int s) {
  vector<vector<ll>> dis(dd + 2, vector<ll>(n + 1, inf));
  dis[0][s] = 0;
  priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
  pq.push({0, s, 0});
  while (!pq.empty()) {
    auto [d, u, roads] = pq.top(); pq.pop();
    if (dis[roads][u] < d) continue;
    for (auto [v, w, type] : g[u]) {
      if (dis[roads + type][v] >= d + w and roads + type <= dd) {
        dis[roads + type][v] = d + w;
        pq.push({dis[roads + type][v], v, roads + type});
      }
    }
  }
  return dis;
}

int cs;
void solve() {
  cin >> n >> m >> k >> dd;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    ++u, ++v;
    g[u].push_back({v, w, 0});
  }
  while (k--) {
    int u, v, w; cin >> u >> v >> w;
    ++u, ++v;
    g[u].push_back({v, w, 1});
  }
  auto dis = dijkstra(1);
  ll ans = inf;
  for (int i = 0; i <= dd; i++) {
    ans = min(ans, dis[i][n]);
  }
  cout << "Case " << ++cs << ": ";
  if (ans >= inf) cout << "Impossible\n";
  else cout << ans << '\n';
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