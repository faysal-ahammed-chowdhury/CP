#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9, inf = 1e9;
vector<int> g[N];
int sz[N], dp[N];

void dfs0(int u, int p) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs0(v, u);
      sz[u] += sz[v];
    }
  }
}

void dfs(int u, int p) {
  vector<int> childs;
  for (auto v : g[u]) {
    if (v != p) {
      childs.push_back(v);
    }
  }
  if (childs.size() == 0) {
    dp[u] = 0;
    return;
  }
  if (childs.size() == 1) {
    dp[u] = sz[u] - 2;
    return;
  }

  int left = childs[0], right = childs[1];
  dfs(left, u);
  dfs(right, u);
  dp[u] = max((sz[right] - 1) + dp[left], (sz[left] - 1) + dp[right]);
}

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

void solve() {
  int n; cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs0(1, 0);
  dfs(1, 0);
  cout << dp[1] << '\n';
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