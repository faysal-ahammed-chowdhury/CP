#include <bits/stdc++.h>
using namespace std;

const int N = 1005, inf = 2e9;
int n, m, a[N][N], dp[N][N];

int fun(int i, int j) {
  if (i > n or j > m) return inf;
  if (i == n and j == m) return a[i][j];
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = a[i][j] + fun(i + 1, j);
  ans = min(ans, a[i][j] + fun(i, j + 1));
  return ans;
}

void path(int i, int j) {
  cout << a[i][j] << ' ';
  if (i == n and j == m) return;
  int left = a[i][j] + fun(i, j + 1);
  int down = a[i][j] + fun(i + 1, j);
  if (left < down) {
    path(i, j + 1);
  }
  else {
    path(i + 1, j);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  cout << fun(1, 1) << '\n';
  path(1, 1);

  return 0;
}