#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 105, M = 105;
int n, m, g[N][M];
bool vis[N][M];

bool ok(int i, int j) {
  if(!(i >= 1 && i <= n && j >= 1 && j <= m)) return false;
  if(vis[i][j]) return false;
  if(g[i][j] == 0) return false;
  return true;
}

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

void dfs(int i, int j) {
  vis[i][j] = true;
  for(int k = 0; k < 8; k++) {
    int new_i = i + dx[k];
    int new_j = j + dy[k];
    if(ok(new_i, new_j)) {
      dfs(new_i, new_j);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin >> n >> m and n != 0) {
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        char c; cin >> c;
        if(c == '*') {
          g[i][j] = 0;
        }
        else {
          g[i][j] = 1;
        }
      }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= m; j++) {
        if(!vis[i][j] && g[i][j]) {
          ++ans;
          dfs(i, j);
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}