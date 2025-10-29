#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
vector<int> g[N];
int par[N], sz[N];

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

void dfs(int u, int p) {
  par[u] = p;
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

void solve() {
  int n, k; cin >> n >> k;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  ll ans = 0;
  for (int u = 1; u <= n; u++) {
    for (auto p : g[u]) {
      if (p == par[u]) {
        if (sz[u] >= k) ans += n - sz[u];
      }
      else {
        int sz_u = n - sz[p];
        if (sz_u >= k) ans += sz[p];
      }
    }
  }

  if (n >= k) ans += n;
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