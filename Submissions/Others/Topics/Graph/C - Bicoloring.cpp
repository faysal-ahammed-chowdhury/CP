#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 9;
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while(cin >> n and n != 0) {
    cin >> m;
    for(int i = 1; i <= m; i++) {
      int u, v; cin >> u >> v;
      u++, v++;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    col[1] = 0;
    ans = true;
    dfs(1);
    cout << (ans ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
    for(int i = 1; i <= n; i++) {
      col[i] = -1;
      g[i].clear();
      vis[i] = false;
    }
  }

  return 0;
}