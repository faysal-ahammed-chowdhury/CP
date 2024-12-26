#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N], gT[N], G[N];
vector<bool> vis(N, false);
vector<int> order;
int n, roots[N], sz[N], cnt[N];

void dfs(int u) {
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) dfs(v);
  }
  order.push_back(u);
}

void dfs1(int u) {
  vis[u] = true;
  for (auto v : G[u]) {
    if (!vis[v]) dfs1(v);
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
        G[roots[v]].push_back(roots[u]);
      }
    }
  }
}

void dfs3(int u) {
  vis[u] = true;
  int cur = 1;
  for (auto v : G[u]) {
    if (!vis[v] and roots[v] == v and sz[v] == 1) {
      dfs3(v);
      cur += cnt[v];
    }
    if (roots[v] == v and sz[v] == 1) {
      cur += cnt[v];
    }
  } 
  cnt[u] = cur;
}

void solve() {
  cin >> n;

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
  }

  order.clear();
  for (int u = 1; u <= n; u++) {
    if (!vis[u] and roots[u] == u and sz[u] == 1) dfs1(u);
  }

  for (int i = 1; i <= n; i++) {
    vis[i] = false;
    cnt[i] = 0;
  }

  for (auto i : order) {
    if (!vis[i] and roots[i] == i and sz[i] == 1) {
      dfs3(i);
    }
  }

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    // cout << cnt[i] << ' ';
    mx = max(mx, cnt[i]);
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