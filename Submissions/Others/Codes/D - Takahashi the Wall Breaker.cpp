#include <bits/stdc++.h>
using namespace std;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1, -2, +2, 0, 0};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1, 0, 0, +2, -2};

using ll = long long;
const int N = 1005, inf = 1e9;
string g[N];
int n, m, dis[N][N];
bool vis[N][N];

bool valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

void dijkstra(int i, int j) {
  dis[i][j] = 0;
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
  pq.push({0, i, j});
  while (!pq.empty()) {
    auto [d, top_i, top_j] = pq.top(); pq.pop();
    if (vis[top_i][top_j]) continue;
    vis[top_i][top_j] = true;
    for (int k = 0; k < 12; k++) {
      int nw_i = top_i + dx[k];
      int nw_j = top_j + dy[k];
      if (!valid(nw_i, nw_j)) continue;

      if (k < 4) {
        int w = g[nw_i][nw_j] == '#';
        if (dis[nw_i][nw_j] > d + w) {
          dis[nw_i][nw_j] = d + w;
          pq.push({dis[nw_i][nw_j], nw_i, nw_j});
        }

      }
      else {
        int w = 1;
        if (dis[nw_i][nw_j] > d + w) {
          dis[nw_i][nw_j] = d + w;
          pq.push({dis[nw_i][nw_j], nw_i, nw_j});
        }
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> g[i];
    g[i] = '.' + g[i];
    for (int j = 1; j <= m; j++) {
      dis[i][j] = inf;
    }
  }

  int src_i, src_j; cin >> src_i >> src_j;
  int dst_i, dst_j; cin >> dst_i >> dst_j;
  dijkstra(dst_i, dst_j);

  cout << dis[src_i][src_j] << '\n';

  return 0;
}