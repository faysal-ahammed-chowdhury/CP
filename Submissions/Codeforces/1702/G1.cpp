#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

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

  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);

  int q; cin >> q;
  while (q--) {
    int k; cin >> k;
    int a[k + 1];
    int mx = -1, node1 = -1; 
    for (int i = 1; i <= k; i++) {
      int u; cin >> u;
      a[i] = u;
      if (depth[u] >= mx) {
        mx = depth[u];
        node1 = u;
      }
    }
    int mx_dis = 0, node2 = -1;
    for (int i = 1; i <= k; i++) {
      int d = dist(node1, a[i]);
      if (d >= mx_dis) {
        mx_dis = d;
        node2 = a[i];
      }
    }
    set<int> se;
    for (int d = 0; d <= mx_dis; d++) {
      se.insert(kth(node1, node2, d));
    }
    bool ok = true;
    for (int i = 1; i <= k; i++) {
      ok &= se.find(a[i]) != se.end();
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
