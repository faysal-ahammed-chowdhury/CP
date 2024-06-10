#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
vector<int> g[N];
int n, cnt1, cnt2, vis[N];

void dfs(int u, int col) {
  if (col == 1) cnt1++;
  else cnt2++;
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v, !col);
    }
  }
}

int cs;
void solve() {
  cin >> n;
  memset(vis, false, sizeof vis);
  for (int i = 0; i < N; i++) {
    g[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0;
  for (int u = 1; u < N; u++) {
    if (!vis[u] and !g[u].empty()) {
      cnt1 = 0, cnt2 = 0;
      dfs(u, 1);
      ans += max(cnt1, cnt2);
    }
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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