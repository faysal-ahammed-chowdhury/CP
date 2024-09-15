#include <bits/stdc++.h>
using namespace std;

const int N = 505;
string g[N];
bool vis[N][N];
int n, m, ans[N][N], cnt;
array<int, 2> par[N][N];

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

bool is_valid(int i, int j) {
  if (!(i >= 1 and i <= n and j >= 1 and j <= m)) return false;
  if (g[i][j] == '#') return false;
  return true;
}

void dfs(int i, int j, int oi, int oj) {
  vis[i][j] = true;
  par[i][j] = {oi, oj};
  if (g[i][j] == 'C') cnt++;
  for (int k = 0; k < 4; k++) {
    int nwi = i + dx[k], nwj = j + dy[k];
    if (is_valid(nwi, nwj) and !vis[nwi][nwj]) {
      dfs(nwi, nwj, oi, oj);
    }
  }
}

int cs;
void solve() {
  int q; cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> g[i];
    g[i] = '.' + g[i];
  }
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        cnt = 0;
        dfs(i, j, i, j);
        ans[i][j] = cnt;
      }
    }
  }
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int i, j; cin >> i >> j;
    auto [ii, jj] = par[i][j];
    cout << ans[ii][jj] << '\n';
  }
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