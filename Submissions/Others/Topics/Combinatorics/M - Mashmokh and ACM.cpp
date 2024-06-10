#include <bits/stdc++.h>
using namespace std;

const int N = 2005, mod = 1e9 + 7;
int n, k, dp[N][N];

int fun(int i, int last) {
  if (i == k + 1) {
    return 1;
  }

  int &ans = dp[i][last];
  if (ans != -1) return ans;

  ans = 0;
  for (int j = last; j <= n; j += last) {
    ans += fun(i + 1, j);
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
    ans += fun(2, i);
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}