#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 9;
set<int> g[N];
set<int> non_vis;
int n;

void dfs(int u) {
  non_vis.erase(u);
  for (int v = 1; v <= n; v++) {
    if (v == u) continue;
    auto it = non_vis.lower_bound(v);
    if (it == non_vis.end()) break;
    v = *it;
    if (g[u].find(v) != g[u].end()) continue;
    dfs(v);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }

  for (int i = 1; i <= n; i++) {
    non_vis.insert(i);
  }

  int component_cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (non_vis.find(i) != non_vis.end()) {
      component_cnt++;
      dfs(i);
    }
  }

  cout << component_cnt - 1 << '\n';

  return 0;
}