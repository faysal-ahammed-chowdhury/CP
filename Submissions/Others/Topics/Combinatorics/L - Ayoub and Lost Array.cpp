#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 1e9 + 7;
int n, l, r, dp[N][3];

int get(int n, int x) {
  int ans = (n / 3);
  if ((n % 3) >= x) ans++;
  return ans;
}

int get2() {
  return (r / 3) - ((l - 1) / 3);
}

int fun(int i, int sum) {
  if (i == n + 1) {
    return (sum == 0 );
  }

  int &ans = dp[i][sum];
  if (ans != -1) return ans;

  ans = 1ll * get2() * fun(i + 1, sum) % mod;
  for (int j = 1; j < 3; j++) {
    ans += 1ll * (get(r, j) - get(l - 1, j)) * fun(i + 1, (sum + j) % 3) % mod;
    ans %= mod;
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n >> l >> r;
  cout << fun(1, 0) <<   '\n';

  return 0;
}