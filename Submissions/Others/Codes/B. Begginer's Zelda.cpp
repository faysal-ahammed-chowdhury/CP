#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
int leaf;

void dfs(int u) {
  vis[u] = true;
  bool is_leaf = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      is_leaf = false;
      dfs(v);
    }
  }
  if (is_leaf) leaf++;
}

void solve() {
  int n; cin >> n;
  int m = n - 1;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  leaf = 0;
  dfs(1);
  if (g[1].size() == 1) leaf++;

  int ans = (leaf + 1) / 2;
  cout << ans << '\n';

  for (int i = 0; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}