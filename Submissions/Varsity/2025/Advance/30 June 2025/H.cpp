#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9; 
vector<int> g[N], gT[N], G[N];
int a[N];
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

void dfs2(int u, vector<int> &component, int &mn) {
  vis[u] = true;
  mn = min(mn, a[u]);
  component.push_back(u);
  for (auto v : gT[u]) {
    if (!vis[v]) dfs2(v, component, mn);
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
      int mn = a[u];
      dfs2(u, component, mn);
      sort(component.begin(), component.end());
      for (auto v : component) {
        roots[v] = component.front();
        a[v] = mn;
      }
    }
  }
  // add edges to condensation graph
  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      if (roots[u] != roots[v]) {
        G[roots[u]].push_back(roots[v]);
        // cout << u << ' ' << v << ' ' << roots[u] << ' ' << roots[v] << '\n';
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    g[i].push_back(x);
  }

  scc();
  set<int> se;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = roots[i];
    // cout << x << ' ' << G[x].size() << '\n';
    if (se.find(x) == se.end()) {
      se.insert(x);
      if (G[x].size() == 0) ans += a[x];
    }
  }

  cout << ans << '\n';

  return 0;
}