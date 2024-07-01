#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
int vis[N], cnt, c[N];
map<int, int> mp;

void dfs(int u) {
  cnt++;
  mp[c[u]]++;
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt = 0;
      mp.clear();
      dfs(i);
      int mx = 0;
      for (auto [_, cnt] : mp) mx = max(mx, cnt);
      ans += cnt - mx;
    }
  }
  cout << ans << '\n';

  return 0;
}
