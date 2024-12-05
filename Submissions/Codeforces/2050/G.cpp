#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9;
vector<int> g[N];
int n, dp[N], dp2[N], ans;

void dfs(int u, int p) {
  vector<int> vec;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      vec.push_back(dp[v]);
    }
  }
  sort(vec.rbegin(), vec.rend());
  ans = max(ans, dp[u]);
  if (vec.size() == 0) return;
  if (vec.size() >= 2) {
    int cur = vec[0] + dp[u] - 2;
    cur += vec[1] - 2;
    ans = max(ans, cur);
  }
  dp[u] = max(dp[u], dp[u] + vec[0] - 2);
  ans = max(ans, dp[u]);
}

void solve() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    dp[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = g[i].size();
    dp2[i] = g[i].size();
    ans = max(ans, dp[i]);
  }
  dfs(1, 0);
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