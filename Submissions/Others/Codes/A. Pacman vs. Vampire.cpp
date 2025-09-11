#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;
vector<string> g;
int n, m, cnt;
vector<vector<int>> dis;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

bool valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m and g[i][j] != '#';
}

void bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  dis[i][j] = 0;
  while (!q.empty()) {
    auto [top_i, top_j] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int nw_i = top_i + dx[k];
      int nw_j = top_j + dy[k];
      if (valid(nw_i, nw_j) and dis[nw_i][nw_j] == inf) {
        q.push({nw_i, nw_j});
        dis[nw_i][nw_j] = dis[top_i][top_j] + 1;
      }
    }
  }
}

void dfs(int i, int j, vector<vector<bool>> &vis) {
  vis[i][j] = true;
  if (g[i][j] == 'V') cnt++;
  for (int k = 0; k < 4; k++) {
    int nw_i = i + dx[k];
    int nw_j = j + dy[k];
    if (valid(nw_i, nw_j) and !vis[nw_i][nw_j]) {
      dfs(nw_i, nw_j, vis);
    }
  }
}

void solve() {
  cin >> n >> m;
  g.resize(n + 1);
  dis.resize(n + 1);
  int src_i, src_j;
  int dst_i, dst_j;
  for (int i = 1; i <= n; i++) {
    dis[i].resize(m + 1);
    cin >> g[i];
    g[i] = '@' + g[i];
    for (int j = 1; j <= m; j++) {
      dis[i][j] = inf;
      if (g[i][j] == 'F') {
        src_i = i, src_j = j;
      }
      if (g[i][j] == 'P') {
        dst_i = i, dst_j = j;
      }
    }
  }

  bfs(src_i, src_j);

  if (dis[dst_i][dst_j] == inf) {
    cnt = 0;
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    dfs(dst_i, dst_j, vis);
    cout << cnt * -10 << '\n';
    return;
  } 

  int ans = 500;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // cout << dis[i][j] << ' ';
      if (g[i][j] == 'V') {
        if (dis[i][j] <= dis[dst_i][dst_j]) ans -= 10;
      }
    }
    // cout << '\n';
  }

  cout << ans << '\n';
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