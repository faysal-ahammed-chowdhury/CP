#include <bits/stdc++.h>
using namespace std;

const int N = 2005, inf = 1e9;
vector<int> g[N];
int n;
string s;
int nxt[N][N];
vector<int> vec;
int dp[N][N];

void dfs(int u, int p) {
  vec.push_back(u);
  for (auto v: g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

int fun(int u, int v) {
  if (v == u) return 1;
  int &ans = dp[u][v];
  if (ans != -1) return ans;
  ans = 0;
  if (s[u] == s[v]) {
    ans = 2 + (nxt[u][v] == v ? 0 : fun(nxt[u][v], nxt[v][u]));
  }
  else {
    ans = max(fun(nxt[u][v], v), fun(u, nxt[v][u]));
  }
  return ans;
}

void solve() {
  cin >> n >> s;
  s = '.' + s;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int u = 1; u <= n; u++) {
    for (auto x : g[u]) {
      vec.clear();
      dfs(x, u);
      for (auto v : vec) {
        nxt[u][v] = x;
      }
    }
  }

  for (int u = 1; u <= n; u++) {
    for (int v = 1; v <= n; v++) {
      dp[u][v] = -1;
    }
  }

  int ans = 0;
  for (int u = 1; u <= n; u++) {
    for (int v = 1; v <= n; v++) {
      ans = max(ans, fun(u, v));
    }
  }
  cout << ans << '\n';

  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}