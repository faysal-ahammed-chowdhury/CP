#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> col(N, -1);
bool ans;

void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      col[v] = !col[u];
      vis[v] = true;
      dfs(v);
    }
    else if(col[v] == col[u]) {
      ans = false;
    }
  }
}

int cs = 0;
void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = true;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      col[i] = 0;
      dfs(i);
    }
  }
  cout << "Scenario #" << ++cs << ":\n";
  cout << (ans ? "No suspicious bugs found!\n" : "Suspicious bugs found!\n");
  for(int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
    col[i] = -1;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}