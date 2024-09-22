#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
const ll inf = 1e15;

vector<array<int, 2>> g[N];
int n, m, h, a[N];

auto dijkstra(int s) {
  array<vector<ll>, 2> dis;
  array<vector<bool>, 2> vis;
  dis[0].resize(n + 1);
  dis[1].resize(n + 1);
  vis[0].resize(n + 1);
  vis[1].resize(n + 1);
  fill(dis[0].begin(), dis[0].end(), inf);
  fill(dis[1].begin(), dis[1].end(), inf);
  fill(vis[0].begin(), vis[0].end(), false);
  fill(vis[1].begin(), vis[1].end(), false);
  dis[a[s]][s] = 0;
  priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
  pq.push({dis[a[s]][s], s, a[s]});
  while (!pq.empty()) {
    auto [d, u, c] = pq.top(); pq.pop();
    if (vis[c][u]) continue;
    vis[c][u] = true;
    for (auto [v, w] : g[u]) {
      if (c) w /= 2;
      int nwc = c | a[v];
      if (dis[nwc][v] > d + w) {
        dis[nwc][v] = d + w;
        pq.push({dis[nwc][v], v, nwc});
      }
    }
  }
  return dis;
}
void solve() {
  cin >> n >> m >> h;
  for (int i = 1; i <= n; i++) { // clear
    g[i].clear();
    a[i] = 0;
  }
  for (int i = 1; i <= h; i++) {
    int x; cin >> x;
    a[x] = 1;
  }
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  auto dis1 = dijkstra(1);
  auto dis2 = dijkstra(n);

  ll ans = dis1[0][n];
  for (int i = 1; i <= n; i++) {
    ll x1 = min(dis1[0][i], dis1[1][i]);
    ll x2 = min(dis2[0][i], dis2[1][i]);
    ans = min(ans, max(x1, x2));
  }
  cout << (ans >= inf ? -1 : ans) << '\n';
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