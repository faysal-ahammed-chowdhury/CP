#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5000 + 9, inf = 1e9;
pair<int, int> dp[2][N];
int n, m;
vector<int> g[N];

void clr(int n) {
  for (int i = 0; i <= n + 5; i++) {
    g[i].clear();
    dp[0][i] = dp[1][i] = {inf, inf};
  }
}

void solve() {
  cin >> n >> m;
  clr(n);
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int time = n + n; time >= 0; time--) {
    for (int u = 1; u <= n; u++) {
      if (u == n) {
        dp[0][u] = {time, 0};
      }
      else {
        int v = g[u][time % g[u].size()];
        pair<int, int> &ans = dp[0][u];
        ans = {dp[1][u].first, dp[1][u].second + 1};
        pair<int, int> tmp = dp[1][v];
        ans = min(ans, tmp);
      }
    }
    swap(dp[0], dp[1]);
  }

  pair<int, int> ans = dp[1][1];
  cout << ans.first << ' ' << ans.second << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}