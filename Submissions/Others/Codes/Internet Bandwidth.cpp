#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105, inf = 1e9;
int n, m, st, en;
int g[N][N], par[N];

int dfs(int u, int p, int mn) {
  // cout << u << ' ' << p << ' ' << mn << '\n';
  par[u] = p;
  if (u == en) return mn;
  int ans = 0;
  for (int v = 1; v <= n; v++) {
    if (par[v] == -1 and g[u][v] > 0) {
      ans = max(ans, dfs(v, u, min(mn, g[u][v])));
    }
  }
  return ans;
}

int cs;
void solve() {
  cin >> n >> st >> en >> m;
  memset(g, 0, sizeof(g));
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u][v] += w;
    g[v][u] += w;
  }
  memset(par, -1, sizeof(par));

  int flow = 0, newflow;
  while ((newflow = dfs(st, 0, inf))) {
    flow += newflow;
    int cur = en;
    while (cur != st) {
      int p = par[cur];
      g[p][cur] -= newflow;
      g[cur][p] += newflow;
      cur = par[cur];
    }
    // cout << newflow << '\n';
    memset(par, -1, sizeof(par));
  }

  cout << "Case " << ++cs << ": " << flow << '\n';
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