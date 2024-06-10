#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5005;
const ll inf = 1e18;
int n, a[N];
ll dp[N][N][2];

ll fun(int i, int j, int last) {
  if (i > j) return 0;
  ll &ans = dp[i][j][last];
  if (ans != -1) return ans;
  ans = -inf;
  if (last & 1) {
    ans = max(ans, fun(i + 1, j, 0));
    ans = min(ans, fun(i, j - 1, 0));
  }
  else {
    ans = max(ans, a[i] + fun(i + 1, j, 1));
    ans = max(ans, a[j] + fun(i, j - 1, 1));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof dp);
  cout << fun(1, n, 0) << '\n';

  return 0;
}