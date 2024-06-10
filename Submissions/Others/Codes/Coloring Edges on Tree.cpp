#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
map<pair<int, int>, int> mp;

void dfs(int u, int p, int skip) {
  int col = 1;
  for (auto v : g[u]) {
    if (v != p) {
      if (col == skip) col++;
      mp[{min(u, v), max(u, v)}] = col;
      dfs(v, u, col);
      col++;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<pair<int, int>> edges;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.push_back({u, v});
  }

  int k = 0;
  for (int i = 1; i <= n; i++) {
    k = max(k, (int)g[i].size());
  }

  dfs(1, -1, 0);
  cout << k << '\n';
  for (auto [u, v] : edges) {
    cout << mp[{min(u, v), max(u, v)}] << '\n';
  }

  return 0;
}