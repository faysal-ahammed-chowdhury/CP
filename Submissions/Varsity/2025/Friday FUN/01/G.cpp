#include <bits/stdc++.h>
using namespace std;

const int N = 12;
string s[N];
int n;
vector<string> v;
bool vis[N][N];

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

void dfs(int i, int j, string res, int baki, int dx, int dy) {
  if (baki == 0 or vis[i][j]) {
    v.push_back(res);
    return;
  }

  vis[i][j] = true;

  int ii = i + dx, jj = j + dy;
  if (ii == 0) ii = n;
  else if (ii == n + 1) ii = 1;

  if (jj == 0) jj = n;
  else if (jj == n + 1) jj = 1;

  // cout << i << ' ' << j << '\n';
  // cout << ii << ' ' << jj << '\n';

  dfs(ii, jj, (res + s[i][j]), baki - 1, dx, dy);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < 8; k++) {
        memset(vis, 0, sizeof vis);
        dfs(i, j, "", 10, dx[k], dy[k]);
      }
    }
  }

  sort(v.rbegin(), v.rend());
  cout << v[0] << '\n';

  return 0;
}