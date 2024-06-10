#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<pair<int, int>> g[N];
int dp[N], id[N];

void dfs(int u) {
  for (auto [v, idx] : g[u]) {
    if (dp[v] == 0) {
      dp[v] = dp[u] + (idx <= id[u]);
      id[v] = idx;
      dfs(v);
    }
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }

  dp[1] = 1, id[1] = 0;
  dfs(1);

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';

  for (int i = 1; i <= n; i++) {
    g[i].clear();
    id[i] = 0;
    dp[i] = 0;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}