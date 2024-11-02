#include <bits/stdc++.h>
using namespace std;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

const int N = 1005;
int n, m, k;
string s[N];
bool vis[N][N];
map<pair<int, int>, pair<int, int>> mp;
map<pair<int, int>, int> ans;

bool is_valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

int dfs(int i, int j) {
  vis[i][j] = true;
  int ans = 0;
  for (int k = 0; k < 4; k++) {
    int newi = i + dx[k];
    int newj = j + dy[k];
    if (is_valid(newi, newj)) {
      if (s[newi][newj] == '.' and !vis[newi][newj]) {
        ans += dfs(newi, newj);
      }
      else if (s[newi][newj] == '*') ans++;
    }
  }
  return ans;
}

void dfs1(int i, int j, int orgi, int orgj) {
  mp[{i, j}] = {orgi, orgj};
  vis[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int newi = i + dx[k];
    int newj = j + dy[k];
    if (is_valid(newi, newj) and s[newi][newj] == '.' and !vis[newi][newj]) {
      dfs1(newi, newj, orgi, orgj);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.' and !vis[i][j]) {
        dfs1(i, j, i, j);
      }
    }
  }
  memset(vis, 0, sizeof vis);
  while (k--) {
    int i, j; cin >> i >> j;
    if (ans.find(mp[{i, j}]) == ans.end()) {
      ans[mp[{i, j}]] = dfs(mp[{i, j}].first, mp[{i, j}].second);
    }
    cout << ans[mp[{i, j}]] << '\n';
  }

  return 0;
}