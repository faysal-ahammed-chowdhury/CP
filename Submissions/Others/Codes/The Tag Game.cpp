#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
int dis1[N], dis2[N];

void dfs(int u, int p, int d, int dis[]) {
  dis[u] = d;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u, d + 1, dis);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1, 0, dis1);
  dfs(x, -1, 0, dis2);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dis2[i] < dis1[i]) {
      ans = max(ans, dis1[i] * 2);
    }
  }
  cout << ans << '\n';

  return 0;
}