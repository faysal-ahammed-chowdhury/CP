#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 105;
vector<int> g[N];
ll a = 1, b = 1, ans[N];

bool is_prime(int n) {
  if (n == 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void prec() {
  bool last = true;
  for (int i = 1; i <= 100; i++) {
    if (is_prime(i)) {
      if (i != 5 and last) a *= i;
      else b *= i;
      last = !last;
    }
  }
}

void dfs(int u, int p, bool is_first) {
  ans[u] = (is_first ? a : b);
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u, !is_first);
    }
  }
}

void solve() {
  int n, m; cin >> n;
  m = n - 1;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0, true);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}