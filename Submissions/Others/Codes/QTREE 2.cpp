#include <bits/stdc++.h>
using namespace std;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 10000 + 9, LOG = 20;
vector<pair<int, int>> g[N];
int par[N][LOG], depth[N], dis[N];

void dfs(int u, int p, int d) {
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  dis[u] = d;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto [v, w] : g[u]) {
    if (v != p) {
      dfs(v, u, d + w);
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int k = depth[u] - depth[v];
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  if (u == v) return u;
  for (int i = LOG - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  return u;
}

int dist(int u, int v) {
  int l = lca(u, v);
  return (dis[u] - dis[l]) + (dis[v] - dis[l]);
}

// kth node from u to v, 0th node is u
int kth(int u, int v, int k) {
  int l = lca(u, v);
  int d = dist(u, v);
  assert(k <= d);
  if (depth[l] + k <= depth[u]) {
    return kth(u, k);
  }
  k -= depth[u] - depth[l];
  return kth(v, depth[v] - depth[l] - k);
}

int cs;
void solve() {
  int n; cin >> n;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    depth[0] = 0;
    dis[i] = 0;
  }

  int m = n - 1;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(1, 0, 0);

  string q;
  while (cin >> q) {
    if (q == "DONE") break;
    if (q == "DIST") {
      int u, v; cin >> u >> v;
      cout << dist(u, v) << '\n';
    }
    else {
      int u, v, k; cin >> u >> v >> k;
      k--;
      cout << kth(u, v, k) << '\n';
    }
  }
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
