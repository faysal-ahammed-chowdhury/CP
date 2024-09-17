#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 1e5 + 9, LOG = 20, inf = 1e9;
vector<array<int, 2>> g[N];
int par[N][LOG], tree[N][LOG], tree2[N][LOG], depth[N];

void dfs(int u, int p, int dis) {
  par[u][0] = p;
  tree[u][0] = dis;
  tree2[u][0] = dis;
  depth[u] = depth[p] + 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
    tree[u][i] = max(tree[u][i - 1], tree[par[u][i - 1]][i - 1]);
    tree2[u][i] = min(tree2[u][i - 1], tree2[par[u][i - 1]][i - 1]);
  }
  for (auto [v, w] : g[u]) {
    if (v != p) {
      dfs(v, u, w);
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
  return (depth[u] - depth[l]) + (depth[v] - depth[l]);
}

int query_max(int u, int v) {
  int l = lca(u, v);
  int d = dist(l, u);
  int ans = 0;
  for (int i = 0; i < LOG; i++) {
    if (CHECK(d, i)) {
      ans = max(ans, tree[u][i]);
      u = par[u][i];
    }
  }
  d = dist(l, v);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(d, i)) {
      ans = max(ans, tree[v][i]);
      v = par[v][i];
    }
  }
  return ans;
}

int query_min(int u, int v) {
  int l = lca(u, v);
  int d = dist(l, u);
  int ans = inf;
  for (int i = 0; i < LOG; i++) {
    if (CHECK(d, i)) {
      ans = min(ans, tree2[u][i]);
      u = par[u][i];
    }
  }
  d = dist(l, v);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(d, i)) {
      ans = min(ans, tree2[v][i]);
      v = par[v][i];
    }
  }
  return ans;
}

int cs;
void solve() {
  int n; cin >> n;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    depth[0] = 0;
  }

  for (int i = 1; i < n; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(1, 0, 0);
  cout << "Case " << ++cs << ":\n";
  int q; cin >> q;
  while (q--) {
    int u, v; cin >> u >> v;
    cout << query_min(u, v) << ' ' << query_max(u, v) << '\n';
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
// https://lightoj.com/problem/min-max-roads