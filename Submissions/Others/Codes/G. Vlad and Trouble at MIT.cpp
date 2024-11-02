#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 9, inf = 1e9;
vector<int> g[N];
int n, dp[N][2];
string s;

void dfs(int u, int p) {
  if (s[u] == 'P') {
    dp[u][0] = 0;
    dp[u][1] = inf;
  }
  else if (s[u] == 'S') {
    dp[u][0] = inf;
    dp[u][1] = 0;
  }
  else {
    dp[u][0] = 0;
    dp[u][1] = 0;
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      dp[u][0] += min(dp[v][0], 1 + dp[v][1]);
      dp[u][1] += min(dp[v][1], 1 + dp[v][0]);
    }
  }
}

void solve() {
  cin >> n;

  for (int i = 0; i <= n; i++) {
    g[i].clear();
    dp[i][0] = dp[i][1] = 0;
  }

  for (int i = 2; i <= n; i++) {
    int v; cin >> v;
    g[i].push_back(v);
    g[v].push_back(i);
  }
  cin >> s;
  s = '.' + s;
  dfs(1, 0);
  cout << min(dp[1][0], dp[1][1]) << '\n';
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