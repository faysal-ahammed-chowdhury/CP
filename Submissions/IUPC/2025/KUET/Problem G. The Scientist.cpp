#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105;
const ll inf = 1e18;
int g[N][N];
ll dis[N][N];
int n, m, S, T, X[N];

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
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u][v] = (g[u][v] != 0 ? min(g[u][v], w) : w);
    g[v][u] = (g[v][u] != 0 ? min(g[v][u], w) : w);
  }

  floyd_warshall();

  cin >> S >> T;
  for (int i = 1; i <= S; i++) {
    cin >> X[i];
  }

  int q; cin >> q;
  while (q--) {
    int p, l, r; cin >> p >> l >> r;
    bool ok = false;
    for (int i = 1; i + 1 <= S; i++) {
      ll st = (1ll * (i - 1) * T) + dis[X[i]][p];
      ll en = (1ll * (i) * T) - dis[X[i + 1]][p];
      if (st <= en) {
        if (en < l or st > r) continue;
        ok = true;
        break;
      }
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}
