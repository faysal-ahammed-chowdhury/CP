#include <bits/stdc++.h>
using namespace std;

const int N = 2005, inf = 1e9;
int n, m;
string s[N];
map<char, vector<pair<int, int>>> mp;
bool vis[N][N];
int dis[N][N];
set<int> se;
pair<int, int> par[N][N];

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

bool valid(int i, int j) {
  return (i >= 1 and i <= n and j >= 1 and j <= m and s[i][j] != '#');
}

void bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  dis[i][j] = 0;
  vis[i][j] = true;
  while (!q.empty()) {
    auto [topi, topj] = q.front(); q.pop();
    if (s[topi][topj] != '.' and s[topi][topj] != '#') {
      if (se.find(s[topi][topj]) == se.end()) {
        se.insert(s[topi][topj]);
        for (auto [nwi, nwj] : mp[s[topi][topj]]) {
          if (nwi == topi and nwj == topj) continue;
          if (valid(nwi, nwj) and !vis[nwi][nwj]) {
            q.push({nwi, nwj});
            vis[nwi][nwj] = true;
            dis[nwi][nwj] = min(dis[nwi][nwj], dis[topi][topj] + 1);
            par[nwi][nwj] = {topi, topj};
          }
        }
      }
    }
    for (int k = 0; k < 4; k++) {
      int nwi = topi + dx[k];
      int nwj = topj + dy[k];
      if (valid(nwi, nwj) and s[nwi][nwj] != '#' and !vis[nwi][nwj]) {
        q.push({nwi, nwj});
        vis[nwi][nwj] = true;
        dis[nwi][nwj] = min(dis[nwi][nwj], dis[topi][topj] + 1);
        par[nwi][nwj] = {topi, topj};
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  int srci, srcj, desti, destj;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '*' + s[i];
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'G') desti = i, destj = j;
      if (s[i][j] == 'S') srci = i, srcj = j;
      mp[s[i][j]].push_back({i, j});
      dis[i][j] = inf;
    }
  }

  bfs(srci, srcj);

  cout << (dis[desti][destj] == inf ? -1 : dis[desti][destj]) << '\n';

  // auto it = 20;
  // int i = desti, j = destj;
  // while (i != srci and j != srcj) {
  //   cout << i << ' ' << j << '\n';
  //   auto [ii, jj] = par[i][j];
  //   i = ii, j = jj;
  // }

  // cout << par[8][11].first << ' ' << par[8][11].second << '\n';

  return 0;
}