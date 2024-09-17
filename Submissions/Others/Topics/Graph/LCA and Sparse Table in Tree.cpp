#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 1e5 + 9, LOG = 20, inf = 1e9; // change here
vector<array<int, 2>> g[N];
int par[N][LOG], tree_mx[N][LOG], tree_mn[N][LOG], depth[N];

void dfs(int u, int p, int dis) {
  par[u][0] = p;
  tree_mx[u][0] = dis;
  tree_mn[u][0] = dis;
  depth[u] = depth[p] + 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
    tree_mx[u][i] = max(tree_mx[u][i - 1], tree_mx[par[u][i - 1]][i - 1]); // change here
    tree_mn[u][i] = min(tree_mn[u][i - 1], tree_mn[par[u][i - 1]][i - 1]); // change here
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
      ans = max(ans, tree_mx[u][i]);
      u = par[u][i];
    }
  }
  d = dist(l, v);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(d, i)) {
      ans = max(ans, tree_mx[v][i]);
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
      ans = min(ans, tree_mn[u][i]);
      u = par[u][i];
    }
  }
  d = dist(l, v);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(d, i)) {
      ans = min(ans, tree_mn[v][i]);
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
  dfs(1, 0, 0); // change here
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