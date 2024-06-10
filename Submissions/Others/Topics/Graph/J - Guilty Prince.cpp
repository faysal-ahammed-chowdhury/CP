#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int g[N][N];
int n, m;
bool vis[N][N];

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

bool ok(int i, int j) {
  if(!(i >= 1 and i <= n and j >= 1 and j <= m)) return false;
  if(vis[i][j]) return false;
  if(g[i][j] == -1) return false;
  return true;
}

int ans;

void dfs(int i, int j) {
  ++ans;
  vis[i][j] = true;
  for(int k = 0; k < 4; k++) {
    int new_i = i + dx[k];
    int new_j = j + dy[k];
    if(ok(new_i, new_j)) {
      dfs(new_i, new_j);
    }
  }
}

int cs = 0;
void solve() {
  cin >> m >> n;
  pair<int, int> start;
  for(int i = 1; i <= n; i++) {
    string s; cin >> s;
    for(int j = 1; j <= m; j++) {
      if(s[j - 1] == '@') {
        g[i][j] = 0;
        start = {i, j};
      }
      else if(s[j - 1] == '.') {
        g[i][j] = 1;
      }
      else {
        g[i][j] = -1;
      }
    }
  }

  ans = 0;
  dfs(start.first, start.second);
  cout << "Case " << ++cs << ": " << ans << '\n';

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      vis[i][j] = false;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}