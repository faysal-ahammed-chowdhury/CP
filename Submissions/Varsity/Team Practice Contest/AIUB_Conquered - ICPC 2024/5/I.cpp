#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 505;
const ll inf = 1e18;
int n, m, t, d, g[N][N], stops[N];
ll dis[N][N];

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
        if (dis[i][k] < inf and dis[k][j] < inf)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}

int main() {
  cin >> n >> m >> t >> d;
  for (int i = 1; i <= t; i++) {
    cin >> stops[i];
  }

  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u][v] = (g[u][v] != 0 ? min(g[u][v], w) : w);
    g[v][u] = (g[v][u] != 0 ? min(g[v][u], w) : w);
  }

  floyd_warshall();
  memset(g, 0, sizeof g);

  if (dis[1][n] <= d) {
    cout << dis[1][n] << '\n';
    return 0;
  }

  for (int i = 1; i <= t; i++) {
    if (dis[1][stops[i]] <= d) {
      g[1][stops[i]] = dis[1][stops[i]];
      g[stops[i]][1] = dis[1][stops[i]];
    }
    if (dis[n][stops[i]] <= d) {
      g[n][stops[i]] = dis[n][stops[i]];
      g[stops[i]][n] = dis[n][stops[i]];
    }
    for (int j = i + 1; j <= t; j++) {
      int u = stops[i], v = stops[j];
      if (dis[u][v] <= d) {
        g[u][v] = dis[u][v];
        g[v][u] = dis[u][v];
      }
    }
  }

  floyd_warshall();

  if (dis[1][n] < inf) cout << dis[1][n] << '\n';
  else cout << "stuck\n";

  return 0;
}
