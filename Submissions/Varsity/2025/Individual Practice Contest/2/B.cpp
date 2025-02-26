#include <bits/stdc++.h>
using namespace std;

const int N = 505, inf = 1e9;
int n;
string s[N];
bool vis[N][N];

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

bool valid(int i, int j) {
  return (i >= 1 and i <= n and j >= 1 and j <= n);
}

bool danger;

void bfs(int i, int j, char c) {
  queue<pair<int, int>> q;
  q.push({i, j});
  vis[i][j] = true;
  while (!q.empty()) {
    auto [topi, topj] = q.front(); q.pop();
    for (int k = 0; k < 8; k++) {
      if (c == '*' and k >= 4) break;
      int nwi = topi + dx[k];
      int nwj = topj + dy[k];
      if (valid(nwi, nwj) and s[nwi][nwj] == c and !vis[nwi][nwj]) {
        q.push({nwi, nwj});
        vis[nwi][nwj] = true;
      }
    }
    if (c == '*') {
      for (int k = 0; k < 8; k++) {
        int nwi = topi + dx[k];
        int nwj = topj + dy[k];
        if (valid(nwi, nwj) and s[nwi][nwj] == '#') {
          danger = true;
        }
      }
    }
  }
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '@' + s[i];
  }

  memset(vis, 0, sizeof vis);

  int ans1 = 0, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] != '.' and !vis[i][j]) {
        danger = false;
        bfs(i, j, s[i][j]);
        if (s[i][j] == '#') ans1++;
        if (danger) ans2++;
      }
    }
  }

  cout << "Case " << ++cs << ": " << ans1 << ' ' << ans2 << '\n';
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