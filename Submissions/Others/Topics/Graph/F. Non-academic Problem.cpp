#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9;
vector<int> g[N];
int disc[N], low[N], timer, n, m, sz[N];
vector<bool> vis(N, false);
map<pair<int, int>, int> bridges;

void bridges_dfs(int u, int p) { // find bridges
  disc[u] = low[u] = ++timer;
  vis[u] = true;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (vis[v]) low[u] = min(low[u], disc[v]);
    else {
      bridges_dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (disc[u] < low[v]) {
        bridges[(make_pair(u, v))]++;
        bridges[(make_pair(v, u))]++;
      }
    }
  }
}

void find_bridges() {
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) {
      timer = 0;
      bridges_dfs(u, -1);
    }
  }
}

void dfs(int u) {
  vis[u] = true;
  sz[u] = 1;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v);
      sz[u] += sz[v];
    }
  }
}

void solve() {
  cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  find_bridges();
  for (int u = 0; u <= n; u++) vis[u] = false;
  dfs(1);
  ll ans = (1ll * n * (n - 1)) / 2;
  for (auto [p, cnt] : bridges) {
    if (cnt > 1) continue;
    auto [u, v] = p;
    int len = min(sz[u], sz[v]);
    int rem = n - len;
    ans = min(ans, ((1ll * rem * (rem - 1)) / 2) + ((1ll * len * (len - 1)) / 2));
  }
  cout << ans << '\n';

  for (int i = 1; i <= n; i++) {
    g[i].clear();
    sz[i] = 0;
    vis[i] = false;
  }
  bridges.clear();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}