#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 2e9;
vector<vector<int>> g;
vector<vector<bool>> vis1, vis2;
int n, m, x, cnt;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

bool ok(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

void dfs1(int i, int j) {
  cnt++;
  vis1[i][j] = true;
  for (int k = 0; k < 8; k++) {
    int new_i = i + dx[k];
    int new_j = j + dy[k];
    if (ok(new_i, new_j) and !vis1[new_i][new_j] and g[new_i][new_j] != 0) {
      dfs1(new_i, new_j);
    }
  }
}

void dfs2(int i, int j) {
  vis2[i][j] = true;
  g[i][j] = cnt;
  for (int k = 0; k < 8; k++) {
    int new_i = i + dx[k];
    int new_j = j + dy[k];
    if (ok(new_i, new_j) and !vis2[new_i][new_j] and g[new_i][new_j] != 0) {
      dfs2(new_i, new_j);
    }
  }
}

int get_dis(int u, int v, int i, int j) { // distance from (u, v) to (i, j)
  if (g[u][v] == 0 and g[i][j] != 0) return g[i][j];
  return 0;
}

int dijkstra(int i, int j) {
  vector<vector<int>> dis(n + 1, vector<int>(m + 1, inf));
  dis[i][j] = g[i][j];
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push({-g[i][j], {i, j}});

  while (!pq.empty()) {
    int d = -pq.top().first;
    int u = pq.top().second.first;
    int v = pq.top().second.second;
    pq.pop();
    for (int k = 0; k < 8; k++) {
      int new_i = u + dx[k];
      int new_j = v + dy[k];
      if (ok(new_i, new_j)) {
        if (dis[new_i][new_j] > d + get_dis(u, v, new_i, new_j)) {
          dis[new_i][new_j] = d + get_dis(u, v, new_i, new_j);
          pq.push({-dis[new_i][new_j], {new_i, new_j}});
        }
      }
    }
  }

  return dis[n][m];
}

void solve() {
  cin >> n >> m >> x;
  g.resize(n + 1, vector<int>(m + 1));
  vis1.resize(n + 1, vector<bool>(m + 1));
  vis2.resize(n + 1, vector<bool>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c; cin >> c;
      g[i][j] = (c == '.' ? -1 : 0);
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      vis1[i][j] = false;
      vis2[i][j] = false;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt = 0;
      if (g[i][j] != 0 and !vis1[i][j]) {
        cnt = 0;
        dfs1(i, j);
        dfs2(i, j);
      }
    }
  }

  int cost = dijkstra(1, 1);
  // cout << cost << '\n';
  cout << (cost <= x ? "Yes" : "No") << '\n';
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