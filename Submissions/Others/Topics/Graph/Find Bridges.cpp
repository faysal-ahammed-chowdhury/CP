#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9; // change here
vector<int> g[N];
int disc[N], low[N], timer, n, m;
vector<bool> vis(N, false);
map<pair<int, int>, int> bridges;

void bridges_dfs(int u, int p) { // find bridges
  disc[u] = low[u] = ++timer;
  vis[u] = true;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (vis[v]) low[u] = min(low[u], disc[v]);
    else {
      bridges_dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (disc[u] < low[v]) {
        bridges[(make_pair(min(u, v), max(u, v)))]++;
      }
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