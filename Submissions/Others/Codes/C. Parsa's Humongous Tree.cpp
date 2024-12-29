#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
vector<int> g[N];
int lo[N], hi[N], n;
ll dp[N][2];

void dfs(int u, int p) {
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      dp[u][0] += max(abs(lo[u] - lo[v]) + dp[v][0], abs(lo[u] - hi[v]) + dp[v][1]);
      dp[u][1] += max(abs(hi[u] - lo[v]) + dp[v][0], abs(hi[u] - hi[v]) + dp[v][1]);
    }
  }
}

void solve() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dp[i][0] = 0;
    dp[i][1] = 0;
  }

  for (int i = 1; i <= n; i++) {
    cin >> lo[i] >> hi[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i][0]);
    ans = max(ans, dp[i][1]);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}