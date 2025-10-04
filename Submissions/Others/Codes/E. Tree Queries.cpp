#include <bits/stdc++.h>
using namespace std;

using ll = long long;
bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

const int N = 2e5 + 9, LOG = 20;
vector<int> g[N];
int par[N][LOG], depth[N];

void dfs(int u, int p) {
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  while (q--) {
    int k; cin >> k;
    vector<pair<int, int>> vec;
    while (k--) {
      int x; cin >> x;
      vec.push_back({depth[x], x});
    }
    sort(vec.rbegin(), vec.rend());

    int node = vec[0].second;
    bool ok = true;
    for (auto [_, v] : vec) {
      int lc = lca(node, v);
      int p = par[v][0];
      ok &= lc == v or lc == p; 
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}