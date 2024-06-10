#include <bits/stdc++.h>
using namespace std;
const int N = 1005, mod = 1e9 + 7, inf = 1e9;
int n, m, dp[N][N];
char a[N][N];

int fun(int i, int j) {
  if (i == n and j == m) {
    return 1;
  }
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = 0;
  if (i + 1 <= n and a[i + 1][j] == '.') ans = (ans + fun(i + 1, j)) % mod;
  if (j + 1 <= m and a[i][j + 1] == '.') ans = (ans + fun(i, j + 1)) % mod;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof dp);

  cout << fun(1, 1) << '\n';

  return 0;
}