#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 2e9;
int n, m, a[N], dp[N];
vector<pair<int, int>> g[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

int dfs(int u, int limit) {
  if (u == 1) return dp[u] = min(a[u], limit);
  int ans = -inf;
  for (auto [v, w] : g[u]) {
    if (w <= limit) {
      int tmp = (dp[v] == -1 ? dfs(v, limit) : dp[v]);
      if (tmp >= w) ans = min(limit, max(ans, tmp + a[u]));
    }
  }
  return dp[u] = ans;
}

bool ok(int limit) {
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  int ans = dfs(n, limit);
  return ans != -inf;
}

void solve() {
  cin >> n >> m;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[v].push_back({u, w});
  }

  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
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