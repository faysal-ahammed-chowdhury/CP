#include <bits/stdc++.h>
using namespace std;

const int N = 105, inf = 1e9;
int n, a[N], dp[N][N][2];

int f(int i, int j, bool now) {
  if (i > j) return 0;
  int &ans = dp[i][j][now], sum = 0;
  if (ans != -1) return ans;
  ans = inf;
  if (now) {
    ans = -inf, sum = 0;
    for (int k = i; k <= j; k++) {
      sum += a[k];
      ans = max(ans, sum + f(k + 1, j, !now));
    }
    sum = 0;
    for (int k = j; k >= i; k--) {
      sum += a[k];
      ans = max(ans, sum + f(i, k - 1, !now));
    }
    return ans;
  }
  for (int k = i; k <= j; k++) {
    sum -= a[k];
    ans = min(ans, sum + f(k + 1, j, !now));
  }
  sum = 0;
  for (int k = j; k >= i; k--) {
    sum -= a[k];
    ans = min(ans, sum + f(i, k - 1, !now));
  }
  return ans;
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof dp);
  cout << "Case " << ++cs << ": " << f(1, n, true) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}