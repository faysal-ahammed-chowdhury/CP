#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, mod = 998244353;
int n;
vector<int> g[N], level[N];
int tot[N], ans[N], mx;

void clr(int n) {
  mx = -1;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    level[i].clear();
    tot[i] = 0;
    ans[i] = 0;
  }
}

void dfs(int u, int p, int lvl) {
  mx = max(mx, lvl);
  ans[u] = 1;
  level[lvl].push_back(u);
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u, lvl + 1);
    }
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[p].push_back(i);
  }

  dfs(1, 0, 1);

  tot[mx] = level[mx].size();

  for (int i = mx - 1; i > 1; i--) {
    for (auto u : level[i]) {
      int here = tot[i + 1];
      for (auto v : g[u]) {
        here -= ans[v];
        if (here < 0) here += mod;
      }
      ans[u] += here;
      ans[u] %= mod;
      tot[i] += ans[u];
      tot[i] %= mod;
    }
  }

  for (auto u : level[1]) {
    int here = tot[2];
    ans[u] += here;
    ans[u] %= mod;
  }

  cout << ans[1] << '\n';
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