#include <bits/stdc++.h>
using namespace std;

const int N = 105, mod = 998244353;
int n, a[N], dp[N][N][N][N];

int f(int i, int sum, int k, int rem) {
  if (i == n + 1) {
    return sum == 0 and rem == 0;
  }
  int &ans = dp[i][sum][k][rem];
  if (ans != -1) return ans;
  ans = f(i + 1, sum, k, rem);
  if (rem) {
    ans += f(i + 1, ((a[i] % k) + sum) % k, k, rem - 1);
    ans %= mod;
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
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f(1, 0, i, i);
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}