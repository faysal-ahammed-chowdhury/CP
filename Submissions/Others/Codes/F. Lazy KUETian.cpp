#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
const ll inf = 1e18;
vector<pair<pair<int, ll>, bool>> g[N];
int n, m, k, s;

auto dijkstra(int s) {
  vector<vector<ll>> dis(n + 1, vector<ll>(k + 1, inf));
  vector<vector<bool>> vis(n + 1, vector<bool>(k + 1, false));
  dis[s][0] = 0;
  priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
  pq.push({0, s, 0}); // dis, node, rev_cnt
  while (!pq.empty()) {
    auto [d, u, cnt] = pq.top(); pq.pop();
    if (vis[u][cnt]) continue;
    vis[u][cnt] = true;
    for (auto [p, type] : g[u]) {
      auto [v, w] = p;
      int nwk = cnt + type;
      if (nwk <= k and dis[v][nwk] > d + w) {
        dis[v][nwk] = d + w;
        pq.push({dis[v][nwk], v, nwk});
      }
    }
  }
  return dis;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k >> s;
  while (m--) {
    ll u, v, w; cin >> u >> v >> w;
    g[u].push_back({{v, w}, 0});
    g[v].push_back({{u, w * 2}, 1});
  }

  auto dis = dijkstra(s);
  ll ans[n + 1];
  for (int i = 1; i <= n; i++) {
    ll x = inf;
    for (int j = 0; j <= k; j++) {
      x = min(x, dis[i][j]);
    }
    ans[i] = x;
  }

  int q; cin >> q;
  short a = -1;
  while (q--) {
    int x; cin >> x;
    if (ans[x] >= inf) cout << -1 << '\n';
    else cout << ans[x] << '\n';
  }

  return 0;
}