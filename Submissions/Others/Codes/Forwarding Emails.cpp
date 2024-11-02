#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
vector<int> g[N], gT[N], cond_g[N];
vector<bool> vis(N, false);
vector<int> order;
int n, roots[N], sz[N], ans[N];

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
        sz[v] = component.size();
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
  if (ans[u] != -1) return;
  ans[u] = sz[u];
  for (auto v : cond_g[u]) {
    dfs3(v);
    ans[u] += ans[v];
  }
}

int cs;
void solve() {
  cin >> n;
  // clear
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    gT[i].clear();
    cond_g[i].clear();
    vis[i] = false;
  }

  for (int i = 1; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }
  scc();
  for (int i = 1; i <= n; i++) {
    ans[i] = -1;
  }
  for (int u = 1; u <= n; u++) {
    if (ans[roots[u]] == -1) {
      dfs3(u);
    }
  }
  int node = N, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i] > cnt) {
      cnt = ans[i];
      node = i;
    }
    else if (ans[i] == cnt) {
      node = min(node, i);
    }
  }
  cout << "Case " << ++cs << ": " << node << '\n';
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