#include <bits/stdc++.h>
using namespace std;

const int N = 2005, mod = 1e9 + 7;
int n, m, dp[N][N][2][2];

int f(int i, int last, bool got_1, bool got_n) {
  if (last > n or last < 1) return 0;
  if (i == m + 1) return got_1 and got_n;
  int &ans = dp[i][last][got_1][got_n];
  if (ans != -1) return ans; 
  ans = f(i + 1, last + 1, got_1 | (last + 1 == 1), got_n | (last + 1 == n));
  ans = (ans + f(i + 1, last - 1, got_1 | (last - 1 == 1), got_n | (last - 1 == n))) % mod;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  int ans = 0;
  memset(dp, -1, sizeof dp);
  for (int last = 1; last <= n; last++) {
    ans = (ans + f(2, last, last == 1, last == n)) % mod;
  }
  cout << ans << '\n';

  return 0;
}