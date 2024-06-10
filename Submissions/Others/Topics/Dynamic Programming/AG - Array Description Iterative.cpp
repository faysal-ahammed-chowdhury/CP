#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, M = 105, mod = 1e9 + 7;
int n, m, a[N], dp[N][M];

int fun(int i, int last) {
  if (last < 1 or last > m) return 0;
  if (i == n + 1) return 1;
  if (a[i] != 0 and abs(a[i] - last) > 1) return 0;
  int &ans = dp[i][last];
  if (ans != -1) return ans;
  ans = 0;
  if (a[i] == 0) {
    ans += fun(i + 1, last);
    if (ans > mod) ans -= mod;
    ans += fun(i + 1, last + 1);
    if (ans > mod) ans -= mod;
    ans += fun(i + 1, last - 1);
    if (ans > mod) ans -= mod;
  }
  else {
    ans += fun(i + 1, a[i]);
    if (ans > mod) ans -= mod;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int last = m; last >= 1; last--) {
      if (i == n + 1) dp[i][last] = 1;
      else if (a[i] != 0 and abs(a[i] - last) > 1) dp[i][last] = 0;
      else {
        int &ans = dp[i][last];
        ans = 0;
        if (a[i] == 0) {
          ans += dp[i + 1][last];
          if (ans > mod) ans -= mod;
          if (last - 1 >= 1) ans += dp[i + 1][last - 1];
          if (ans > mod) ans -= mod;
          if (last + 1 <= m) ans += dp[i + 1][last + 1];
          if (ans > mod) ans -= mod;
        }
        else {
          ans += dp[i + 1][a[i]];
          if (ans > mod) ans -= mod;
        }
      }
    }
  }

  if (a[1] != 0) {
    cout << dp[2][a[1]] << '\n';
  }
  else {
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      ans += dp[2][i];
      if (ans > mod) ans -= mod;
    }
    cout << ans << '\n';
  }

  return 0;
}