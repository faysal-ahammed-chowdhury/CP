#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[] = { +1, +1, +2, +2, -1, -1, -2, -2};
int dy[] = { +2, -2, +1, -1, +2, -2, +1, -1};

const int N = 12, inf = 1e9;
string s[N];
int n, m, dis[N][N];
bool vis[N][N];

bool is_valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

void bfs(int i, int j) {
  dis[i][j] = 0;
  vis[i][j] = true;
  queue<array<int, 2>> q;
  q.push({i, j});
  while (!q.empty()) {
    auto [topi, topj] = q.front(); q.pop();
    // cout << "here:\n";
    // cout << topi << ' ' << topj << ' ' << dis[topi][topj] << '\n';
    for (int k = 0; k < 8; k++) {
      int nwi = topi + dx[k];
      int nwj = topj + dy[k];
      if (is_valid(nwi, nwj) and !vis[nwi][nwj]) {
        // cout << nwi << ' ' << nwj << '\n';
        dis[nwi][nwj] = dis[topi][topj] + 1;
        q.push({nwi, nwj});
        vis[nwi][nwj] = true;
      }
    }
  }
}

int cs;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }

  ll ans = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int ii = 1; ii <= n; ii++) {
        for (int jj = 1; jj <= m; jj++) {
          vis[ii][jj] = false;
          dis[ii][jj] = inf;
        }
      }
      bfs(i, j);
      ll tot = 0;
      bool flag = false;
      for (int ii = 1; ii <= n; ii++) {
        for (int jj = 1; jj <= m; jj++) {
          if (s[ii][jj] >= '0' and s[ii][jj] <= '9') {
            int x = s[ii][jj] - '0';
            int d = (dis[ii][jj] + x - 1) / x;
            tot += d;
            flag |= dis[ii][jj] >= inf;
            // cout << ii << ' ' << jj << ' ' << d << '\n';
          }
        }
      }
      if (!flag) ans = min(ans, tot);
    }
  }
  cout << "Case " << ++cs << ": " << (ans >= inf ? -1 : ans) << '\n';
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