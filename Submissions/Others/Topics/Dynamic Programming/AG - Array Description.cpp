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

  memset(dp, -1, sizeof(dp));
  if (a[1] != 0) {
    cout << fun(2, a[1]) << '\n';
  }
  else {
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      ans += fun(2, i);
      if (ans > mod) ans -= mod;
    }
    cout << ans << '\n';
  }

  return 0;
}