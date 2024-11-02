#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 505;
const ll inf = 1e18;
int g[N][N], nxt[N][N];
ll dis[N][N];
int n, m;

vector<int> construct_path(int u, int v) {
  if (nxt[u][v] == -1) return {};
  vector<int> path = { u };
  while (u != v) {
    u = nxt[u][v];
    path.push_back(u);
  }
  return path;
}

void floyd_warshall() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) dis[i][j] = 0;
      else if (g[i][j] == 0) dis[i][j] = inf;
      else dis[i][j] = g[i][j];
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dis[i][k] >= inf or dis[k][j] >= inf) continue;
        if (dis[i][k] + dis[k][j] <= dis[i][j]) {
          dis[i][j] = dis[i][k] + dis[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }
}

int main() {
  int q; cin >> n >> m >> q;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u][v] = (g[u][v] != 0 ? min(g[u][v], w) : w);
    g[v][u] = (g[v][u] != 0 ? min(g[v][u], w) : w);
  }

  memset(nxt, -1, sizeof nxt);
  floyd_warshall();

  while (q--) {
    int u, v; cin >> u >> v;
    cout << (dis[u][v] == inf ? -1 : dis[u][v]) << '\n';
  }

  return 0;
}
