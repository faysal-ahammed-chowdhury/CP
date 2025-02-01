#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e4 + 9, K = 505;
vector<int> g[N];
int n, k, dp[N][K];
ll ans;

void dfs(int u, int p) {
  dp[u][0] = 1;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int i = 1; i <= k; i++) {
      int need = k - i;
      if (need > 0) {
        ans += 1ll * dp[v][i - 1] * dp[u][need];
        // cout << u << '-' << v << ' ' << i << ' ' << need << ' ' << dp[u][need] << '\n';
      }
    }
    for (int i = 1; i <= k; i++) dp[u][i] += dp[v][i - 1];
  }
  ans += dp[u][k];
  // cout << "here: " << u << ' ' << dp[u][k] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  cout << ans << '\n';

  // for (int u = 1; u <= n; u++) {
  //   cout << u << ": ";
  //   for (int i = 0; i <= k; i++) {
  //     cout << dp[u][i] << ' ';
  //   }
  //   cout << '\n';
  // }

  return 0;
}