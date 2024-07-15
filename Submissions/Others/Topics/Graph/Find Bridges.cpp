#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9; // change here
vector<int> g[N];
int disc[N], low[N], timer, n, m;
vector<bool> vis(N, false);
map<pair<int, int>, bool> bridges;

void IS_BRIDGE(int u, int v) {
  if (bridges.find(make_pair(u, v)) != bridges.end()) {
    bridges.erase(make_pair(u, v));
    bridges.erase(make_pair(v, u));
  }
  else {
    bridges[(make_pair(u, v))] = true;
    bridges[(make_pair(v, u))] = true;
  }
}

void bridges_dfs(int u, int p) { // find bridges
  disc[u] = low[u] = ++timer;
  vis[u] = true;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (vis[v]) low[u] = min(low[u], disc[v]);
    else {
      bridges_dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (disc[u] < low[v]) IS_BRIDGE(u, v);
    }
  }
}

void find_bridges() {
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) {
      timer = 0;
      bridges_dfs(u, -1);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}