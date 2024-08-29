#include <bits/stdc++.h>
using namespace std;

const int N = 10000 + 9;
vector<int> g[N];
int disc[N], low[N], timer, n, m;
vector<bool> vis(N, false), is_ap(N, false);

void ap_dfs(int u, int p) {
  disc[u] = low[u] = ++timer;
  vis[u] = true;
  int children_cnt = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (vis[v]) low[u] = min(low[u], disc[v]);
    else {
      ap_dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (disc[u] <= low[v] and p != -1) is_ap[u] = true;
      children_cnt++;
    }
  }
  if (p == -1 and children_cnt > 1) is_ap[u] = true;
}

void find_articulation_points() { 
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) {
      timer = 0;
      ap_dfs(u, -1);
    }
  }
}

int cs;
void solve() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
    is_ap[i] = false;
  }
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  find_articulation_points();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (is_ap[i]) ans++;
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