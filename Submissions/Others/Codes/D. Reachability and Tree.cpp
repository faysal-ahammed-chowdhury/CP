#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
vector<int> g[N];
vector<pair<int, int>> ans;

void clr(int n) {
  ans.clear();
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

void dfs(int u, int p, bool op, int lvl) {
  if (p != -1) {
    if (op) {
      if (lvl & 1) ans.push_back({u, p});
      else ans.push_back({p, u});
    }
    else {
      if (lvl & 1) ans.push_back({p, u});
      else ans.push_back({u, p});
    }
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u, (op | (p == -1 and v == g[u].back())), lvl + 1);
    }
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

  if (n == 2) {
    cout << "NO\n";
    return;
  }

  int p = -1;
  for (int u = 1; u <= n; u++) {
    if (g[u].size() == 2) {
      p = u;
    }
  }

  if (p == -1) {
    cout << "NO\n";
    return;
  }

  dfs(p, -1, false, 0);
  assert(ans.size() == n - 1);
  cout << "YES\n";
  for (auto [u, v] : ans) {
    cout << u << ' ' << v << '\n';
  }
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