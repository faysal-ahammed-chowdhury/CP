#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3005;
const ll inf = 1e16;
int a[N][N], n, m, k;
ll dp[N][N][5];

ll f(int i, int j, int cnt) {
  if (i > n or j > m) return -inf;
  if (i == n and j == m) return (cnt < 3 ? a[i][j] : 0ll);
  ll &ans = dp[i][j][cnt];
  if (ans != -1) return ans;
  ans = f(i + 1, j, cnt);
  ans = max(ans, f(i, j + 1, cnt));
  if (cnt + 1 <= 3) {
    ans = max(ans, a[i][j] + f(i + 1, j, 0));
    ans = max(ans, a[i][j] + f(i, j + 1, cnt + 1));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  while (k--) {
    int i, j, val; cin >> i >> j >> val;
    a[i][j] = val;
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  memset(dp, -1, sizeof dp);
  cout << f(1, 1, 0) << '\n';

  return 0;
}