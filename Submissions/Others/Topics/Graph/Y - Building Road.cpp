#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);

void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m-- > 0) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> ans;
  int components = 0;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      dfs(i);
      ans.push_back(i);
      ++components;
    }
  }

  cout << --components << '\n';
  for(int i = 0; i < components; i++) {
    cout << ans[i] << ' ' << ans[i + 1] << '\n';
  }

  return 0;
}