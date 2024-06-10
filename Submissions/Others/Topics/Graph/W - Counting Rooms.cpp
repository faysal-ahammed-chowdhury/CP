#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
string s[N];
bool vis[N][N];
int n, m;

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

bool ok(int i, int j) {
  if(!(i >= 0 and i < n and j >= 0 and j < m)) return false;
  if(vis[i][j]) return false;
  if(s[i][j] == '#') return false;
  return true;
}

void dfs(int i, int j) {
  vis[i][j] = true;
  for(int k = 0; k < 4; k++) {
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

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j= 0; j < m; j++) {
      if(!vis[i][j] and s[i][j] == '.') {
        ++ans;
        dfs(i, j);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}