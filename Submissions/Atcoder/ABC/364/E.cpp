#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 82, MAX = 1e4 + 9, inf = 1e18;
pair<int, int> a[N];
int n, x, y, dp[N][N][MAX];

int f(int i, int nibo, int sweet) {
  if (i == n + 1) return nibo == 0 ? 0 : inf;
  int &ans = dp[i][nibo][sweet];
  if (ans != -1) return ans;
  ans = f(i + 1, nibo, sweet);
  if (nibo > 0 and sweet - a[i].first >= 0) {
    ans = min(ans, a[i].second + f(i + 1, nibo - 1, sweet - a[i].first));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  memset(dp, -1, sizeof dp);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int salt = f(1, i, x);
    if (salt <= y) ans = max(ans, i + 1);
  }
  cout << min(ans, n) << '\n';

  return 0;
}