#include <bits/stdc++.h>
using namespace std;

const int N = 12, inf = 1e9;
string g[N];
bool vis[N][N];
int n, dis[N][N];

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

bool is_valid(int i, int j, int node) {
  if (!(i >= 1 and i <= n and j >= 1 and j <= n)) return false;
  if (g[i][j] == '#') return false;
  if (g[i][j] >= 'A' and g[i][j] <= 'Z' and g[i][j] > char(node + 'A' + 1)) return false;
  return true;
}

void bfs(int i, int j, int node) {
  vis[i][j] = true;
  dis[i][j] = 0;
  queue<array<int, 2>> q;
  q.push({i, j});
  while (!q.empty()) {
    auto [topi, topj] = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int nwi = topi + dx[k];
      int nwj = topj + dy[k];
      if (is_valid(nwi, nwj, node) and !vis[nwi][nwj]) {
        dis[nwi][nwj] = dis[topi][topj] + 1;
        q.push({nwi, nwj});
        vis[nwi][nwj] = true;
      }
    }
  }
}

int cs;
void solve() {
  cin >> n;
  map<int, array<int, 2>> mp;
  for (int i = 1; i <= n; i++) {
    cin >> g[i];
    g[i] = '.' + g[i];
    for (int j = 1; j <= n; j++) {
      if (g[i][j] >= 'A' and g[i][j] <= 'Z') {
        mp[(g[i][j] - 'A')] = {i, j};
      }
    }
  }
  int ans = 0;
  for (auto [node, p] : mp) {
    auto [i, j] = p;
    memset(vis, false, sizeof vis);
    bfs(i, j, node);
    if (mp.find(node + 1) != mp.end()) {
      auto [ii, jj] = mp[node + 1];
      if (vis[ii][jj]) ans += dis[ii][jj];
      else {
        ans = inf;
        break;
      }
    }
  }
  cout << "Case " << ++cs << ": ";
  if (ans >= inf) cout << "Impossible\n";
  else cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}