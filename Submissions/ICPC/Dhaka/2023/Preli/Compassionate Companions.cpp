#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int a[N][N], n, col[N];
vector<int> g[N];
bool is_bipartite, vis[N];

void dfs(int u, int c) {
  vis[u] = true;
  col[u] = c;
  for (auto v : g[u]) {
    if (col[v] != -1 and col[v] == c) {
      is_bipartite = false;
    }
    if (!vis[v]) {
      dfs(v, !c);
    }
  }
}

bool ok(int mid) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
    col[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (a[i][j] < mid) g[i].push_back(j);
    }
  }
  is_bipartite = true;
  for (int i = 1; i <= n and is_bipartite; i++) {
    if (!vis[i]) dfs(i, 0);
  }
  return is_bipartite;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }
  cout << ans << '\n';

  return 0;
}