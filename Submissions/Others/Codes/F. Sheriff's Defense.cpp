#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
vector<int> g[N];
ll dp[N][2];
int n, c, a[N];

void dfs(int u, int p) {
  dp[u][0] = 0;
  dp[u][1] = a[u];
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      dp[u][0] += max(dp[v][0], dp[v][1]);
      dp[u][1] += max(dp[v][0], dp[v][1] - (2 * c));
    }
  }
}

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

void solve() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << max(dp[1][0], dp[1][1]) << '\n';
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