#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, mod = 1e9 + 7;
vector<int> g[N];
int dp[2][N];

void dfs(int u, int p) {
  dp[0][u] = 1;
  dp[1][u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      dp[0][u] = 1ll * dp[0][u] * dp[1][v] % mod;
      dp[1][u] = ((1ll * dp[1][u] * dp[0][v] % mod) + (1ll * dp[1][u] * dp[1][v]) % mod) % mod;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  cout << (dp[0][1] + dp[1][1]) % mod << '\n';

  return 0;
}