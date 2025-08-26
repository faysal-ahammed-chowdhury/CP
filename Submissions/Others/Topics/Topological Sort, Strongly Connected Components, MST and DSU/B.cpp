#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100 + 9;
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

void clr(int n) {
  components.clear();
  order.clear();
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    gT[i].clear();
    G[i].clear();
    vis[i] = false;
  }
}

// when you need to use condensed graph, use it carefully (Specially g->G, i->roots[i])
void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'Y') {
        g[i].push_back(j + 1);
        // cout << i << ' ' << j + 1 << '\n';
      }
    }
  }

  scc();

  cout << components.size() << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}