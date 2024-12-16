#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9; // change here
vector<int> g[N], gT[N], G[N];
vector<bool> vis(N, false);
vector<vector<int>> components;
vector<int> order;
int n, roots[N], sz[N], dep[N];

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

void dfs3(int u) {
  vis[u] = true;
  int d = 0;
  for (auto v : g[u]) {
    if (!vis[v] and roots[v] == v and sz[v] == 1) {
      dfs3(v);
    }
    if (roots[v] == v and sz[v] == 1) {
      d = max(d, dep[v]);
    }
  } 
  dep[u] = d + 1;
}

void solve() {
  cin >> n;

  components.clear();
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    gT[i].clear();
    G[i].clear();
    vis[i] = false;
  }


  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    g[i].push_back(x);
  }
  scc();

  for (int i = 1; i <= n; i++) {
    vis[i] = false;
    dep[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i] and roots[i] == i and sz[i] == 1) {
      dfs3(i);
    }
  }

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    // cout << dep[i] << ' ';
    mx = max(mx, dep[i]);
  }

  cout << mx + 2 << '\n';
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