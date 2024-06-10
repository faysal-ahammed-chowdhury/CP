#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
int ans[N];

void dfs(int u, int x) {
  vis[u] = true;
  ans[u] = x;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v, (x == 1 ? 2 : 1));
    }
  }
}

void solve() {
  int n, m; cin >> n;
  m = n - 1;
  for(int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

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