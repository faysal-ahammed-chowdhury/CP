#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
vector<int> g[N], gT[N], G[N];
vector<bool> vis(N, false);
vector<vector<int>> components;
vector<int> order;
int n, roots[N], sz[N];

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
  components.clear();
  for (int i = 1; i <= n; i++) vis[i] = false;
  for (auto u : order) {
    if (!vis[u]) {
      vector<int> component;
      dfs2(u, component);
      sort(component.begin(), component.end());
      components.push_back(component);
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
        G[roots[u]].push_back(roots[v]);
      }
    }
  }
}

// when you need to use condensed graph, use it carefully (Specially g->G, i->roots[i])
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }

  scc();

  int cnt = 0;
  int root = -1;
  for (int i = 1; i <= n; i++) {
    if (i == roots[i] and G[i].size() == 0) {
      cnt++;
      root = i;
    }
  }

  if (cnt == 1) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (roots[i] == root) v.push_back(i);
    }
    cout << v.size() << '\n';
    for (auto x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  else cout << 0 << '\n';

  return 0;
}