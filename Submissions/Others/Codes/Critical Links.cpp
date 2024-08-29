#include <bits/stdc++.h>
using namespace std;

const int N = 10005; 
vector<int> g[N];
int disc[N], low[N], timer, n;
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

int cs;
void solve() {
  bridges.clear();
  cin >> n;
  for (int i = 0; i <= n; i++) {
    vis[i] = false;
    g[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    int u, k; char c; cin >> u >> c >> k >> c;
    ++u;
    for (int j = 1; j <= k; j++) {
      int v; cin >> v;
      ++v;
      g[u].push_back(v);
    } 
  }
  // for (int i = 1; i <= n; i++) {
  //   cout << i << ": ";
  //   for (auto v : g[i]) {
  //     cout << v << ' ';
  //   }
  //   cout << '\n';
  // }
  find_bridges();
  vector<pair<int, int>> ans;
  for (auto [p, cnt] : bridges) {
    if (cnt == 1) {
      auto [u, v] = p;
      ans.push_back({u, v});
    }
  }
  cout << "Case " << ++cs << ":\n";
  cout << ans.size() << " critical links" << '\n'; 
  for (auto [u, v] : ans) {
    cout << --u << " - " << --v << '\n';
  }
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