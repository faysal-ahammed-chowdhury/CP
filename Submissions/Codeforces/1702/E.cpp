#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> col(N, -1);
bool ans;

void dfs(int u) {
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) {
      // cout << u << ' ' << v << '\n';
      col[v] = !col[u];
      vis[v] = true;
      dfs(v);
    }
    else if (col[v] == col[u]) {
      ans = false;
    }
  }
}

void solve() {
  int n; cin >> n;

  for (int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
    col[i] = -1;
  }

  vector<int> a[n + 1];
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    a[x].push_back(i);
    a[y].push_back(i);
    if (x == y) ok = false;
    if (a[x].size() > 2) ok = false;
    if (a[y].size() > 2) ok = false;
  }
  if (!ok) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].size() == 2) {
      int u = a[i][0], v = a[i][1];
      // cout << u << ' ' << v << '\n';
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  ans = true;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      col[i] = 0;
      dfs(i);
    }
  }
  if (ans) cout << "YES\n";
  else cout << "NO\n";
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