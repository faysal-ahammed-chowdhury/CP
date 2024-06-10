#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int dp[N];

int dfs(int u) {
  if (dp[u] != -1) return dp[u];
  int ans = 0;
  for (auto v: g[u]) {
    ans = max(ans, 1 + dfs(v));
  }
  return dp[u] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }

  memset(dp, -1, sizeof(dp));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dfs(i));
  }
  cout << ans << '\n';

  return 0;
}