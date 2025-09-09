#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n, k, lvl[N];
vector<int> g[N];
int a[N];
bitset<N> dp;

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    a[i] = 0;
  }
}

void dfs(int u, int p) {
  lvl[u] = lvl[p] + 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

void f() {
  for (int i = n + 1; i >= 1; i--) {
    if (i == n + 1) {
      dp = 0;
      dp[0] = 1;
    }
    else {
      dp = dp | (dp << a[i]);
    }
  }
}

void solve() {
  cin >> n >> k;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[i].push_back(p);
    g[p].push_back(i);
  }

  dfs(1, 0);
  int ans = n;
  for (int i = 2; i <= n; i++) {
    if (g[i].size() == 1) {
      ans = min(ans, lvl[i]);
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (lvl[i] <= ans) {
      a[lvl[i]]++;
      cnt++;
    }
  }
  cnt = n - cnt;

  f();
  for (int i = k; i >= 0; i--) {
    if (dp[i]) {
      int d = k - i;
      if (d <= cnt) {
        cout << ans << '\n';
        return;
      }
    }
  }

  cout << --ans << '\n';
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