#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int dp[N][2];

void dfs(int u, int p) {
  dp[u][0] = 0;
  dp[u][1] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      dp[u][0] += dp[v][1];
      dp[u][1] += min(dp[v][0], dp[v][1]);
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
  cout << min(dp[1][0], dp[1][1]) << '\n';

  return 0;
}