#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18;
const int N = 405;
int n, a[N];
long long dp[N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    dp[i][i] = 0;
  }

  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      if (i >= j) continue;
      ll &ans = dp[i][j];
      ll cur = 0;
      for (int x = i; x <= j; x++) {
        cur += a[x];
      }
      ans = inf;
      for (int x = i; x < j; x++) {
        ans = min(ans, cur + dp[i][x] + dp[x + 1][j]);
      }
    }
  }

  cout << dp[1][n] << '\n';

  return 0;
}