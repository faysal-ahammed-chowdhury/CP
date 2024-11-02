#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
vector<int> g[N];
int n, a[N];
ll dp[N][45], dp2[N][45];

void dfs(int u, int p) {
  for (int i = 1; i <= 40; i++) {
    dp[u][i] = i * a[u];
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      for (int i = 1; i <= 40; i++) {
        dp[u][i] += dp[v][i - 1];
      }
    }
  }
}

void dfs2(int u, int p) {
  for (int i = 2; u != 1 and i <= 40; i++) {
    dp2[u][i] = dp[p][i - 1] - dp[u][i - 2];
    // cout << u << ' ' << i << ' ' << dp2[u][i] << '\n';
  }
  for (int i = 1; i <= 40; i++) {
    dp2[u][i] += dp2[p][i - 1];
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs2(v, u);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 0);
  
  int q; cin >> q;
  while (q--) {
    int u, t; cin >> u >> t;
    int extra = t - 40;
    t = min(40, t);
    ll ans = dp[u][t] + dp2[u][t];
    if (extra > 0) ans += 1ll * extra * sum;
    cout << ans << '\n';
  }

  return 0;
}