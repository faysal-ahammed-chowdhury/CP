#include <bits/stdc++.h>
using namespace std;

const int N = 10005; 
vector<int> g[N], gT[N], G[N];
vector<bool> vis(N, false);
vector<int> order;
int n, m, roots[N], indeg[N];

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
        G[roots[u]].push_back(roots[v]);
        indeg[roots[v]]++;
      }
    }
  }
}

void dfs3(int u) {
  vis[u] = true;
  for (auto v : G[u]) {
    if (!vis[v]) dfs(v);
  }
}

int cs;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    gT[i].clear();
    G[i].clear();
    vis[i] = false;
    indeg[i] = 0;
  }

  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }
  scc();

  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(indeg[roots[i]] == 0) {
      q.push(roots[i]);
    }
  }

  vector<int> toporder;
  while(!q.empty()) {
    int top = q.front();
    q.pop();
    toporder.push_back(top);
    for(auto v: G[top]) {
      indeg[v]--;
      if(indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  fill(vis.begin(), vis.end(), false);
  int ans = 0;
  for (auto u : toporder) {
    if (!vis[u]) {
      dfs3(u);
      ans++;
    }
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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