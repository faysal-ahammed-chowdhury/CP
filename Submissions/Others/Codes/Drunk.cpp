#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> g;
map<string, int> vis;
bool has_cycle;

void dfs(string u) {
  vis[u] = 1;
  for (auto v : g[u]) {
    if (vis[v] == 0) {
      dfs(v);
    }
    else if (vis[v] == 1) {
      has_cycle = true;
      return;
    }
  }
  vis[u] = 2;
}

int cs;
void solve() {
  g.clear();
  vis.clear();
  int n; cin >> n;
  set<string> se;
  for (int i = 1; i <= n; i++) {
    string u, v; cin >> u >> v;
    g[u].push_back(v);
    se.insert(u);
    se.insert(v);
  }
  has_cycle = false;
  for (auto u : se) {
    if (vis[u] == 0) {
      dfs(u);
    }
  }
  cout << "Case " << ++cs << ": " << (has_cycle ? "No" : "Yes") << '\n';
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