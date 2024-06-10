#include <bits/stdc++.h>
using namespace std;

const int N = 105, inf = 1e9;
int n, m, a[N][N], dp[N][N][N];

bool is_valid(int x, int y) {
  return x <= n and y <= m;
}

int f(int x1, int y1, int x2, int y2) {
  if (!is_valid(x1, y1)) return -inf;
  if (!is_valid(x2, y2)) return -inf;
  if (x1 == n and y1 == m and x2 == n and y2 == m) return a[n][m];
  if (x1 == x2 and y1 == y2) return -inf;
  int &ans = dp[x1][x2][y1];
  if (ans != -1) return ans;
  ans = a[x1][y1] + a[x2][y2] + f(x1 + 1, y1, x2 + 1, y2);
  ans = max(ans, a[x1][y1] + a[x2][y2] + f(x1 + 1, y1, x2, y2 + 1));
  ans = max(ans, a[x1][y1] + a[x2][y2] + f(x1, y1 + 1, x2 + 1, y2));
  ans = max(ans, a[x1][y1] + a[x2][y2] + f(x1, y1 + 1, x2, y2 + 1));
  return ans;
}

int cs;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << "Case " << ++cs << ": ";
  cout << a[1][1] + f(1,2,2,1) << '\n';
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