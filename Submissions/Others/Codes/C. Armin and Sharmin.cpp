#include <bits/stdc++.h>
using namespace std;

const int N = 2005, mod = 1e9 + 7;
int n, k, dp[N][N];

int fun(int x, int cnt) {
  if (x > n) return 0;
  if (cnt == k) {
    return 1;
  }
  int &ans = dp[x][cnt];
  if (ans != -1) return ans;
  ans = 0;
  for (int i = x; i <= n; i += x) {
    ans += fun(i, cnt + 1);
    ans %= mod;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n >> k;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += fun(i, 1);
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}