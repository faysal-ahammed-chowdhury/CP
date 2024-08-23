#include <bits/stdc++.h>
using namespace std;

const int N = 1005; // change here
vector<int> g[N], gT[N], cond_g[N];
vector<bool> vis(N, false);
vector<int> order;
int n, roots[N];

void dfs(int u) {
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) dfs(v);
  }
  order.push_back(u);
}

void dfs2(int u, vector<int> &component) {
  vis[u] = true;
  component.push_back(u);
  for (auto v : gT[u]) {
    if (!vis[v]) dfs2(v, component);
  }
}

void scc() {
  // get order sorted by end time
  order.clear();
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) dfs(u);
  }
  reverse(order.begin(), order.end());
  // transpose the graph
  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      gT[v].push_back(u);
    }
  }
  // get all components
  for (int i = 1; i <= n; i++) vis[i] = false;
  for (auto u : order) {
    if (!vis[u]) {
      vector<int> component;
      dfs2(u, component);
      sort(component.begin(), component.end());
      for (auto v : component) {
        roots[v] = component.front();
      }
    }
  }
  // add edges to condensation graph
  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      if (roots[u] != roots[v]) {
        cond_g[roots[u]].push_back(roots[v]);
      }
    }
  }
}

void dfs3(int u) {
  vis[u] = true;
  if (cond_g[u].size() == 0) return;
  int v = cond_g[u][0];
  if (!vis[v]) dfs3(v);
}

int cs;
void solve() {
  n = 1000;
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
    g[i].clear();
    gT[i].clear();
    cond_g[i].clear();
  }
  int m; cin >> m;
  vector<int> vec;
  while (m--) {
    int k; cin >> k;
    while (k--) {
      int u, v; cin >> u >> v;
      ++u, ++v;
      g[u].push_back(v);
      vec.push_back(u);
      vec.push_back(v);
    }
  }

  scc();

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    ok &= cond_g[i].size() <= 1;
  }

  // for (int i = 1; i <= 1000; i++) {
  //   cout << i << ": ";
  //   for (auto v : cond_g[i]) cout << v << ' '; cout << '\n';
  // }

  for (int i = 1; i <= n; i++) vis[i] = false;
  dfs3(1);
  for (auto v : vec) {
    ok &= vis[roots[v]];
  }
  cout << "Case " << ++cs << ": " << (ok ? "YES" : "NO") << '\n';
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