#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> col(N, -1);
int cnt[2];

void dfs(int u) {
  cnt[col[u]]++;
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      col[v] = !col[u];
      vis[v] = true;
      dfs(v);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  col[1] = 0;
  dfs(1);
 
  long long ans = 1ll * cnt[0] * cnt[1] - (n - 1);
  cout << ans << '\n';

  return 0;
}