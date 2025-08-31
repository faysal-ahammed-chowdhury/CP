#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 9, mod = 1e9 + 7;
int n, a[N], dp[N][2525];

int f(int i, int cur) {
  if (i > n) return cur == 0;
  // cout << i << ' ' << cur << '\n';
  int &ans = dp[i][cur];
  if (ans != -1) return ans;
  ans = f(i + 1, cur);
  ans = (ans + f(i + 1, 1ll * cur * a[i] % 2520)) % mod;
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
  cout << f(1, 1) << '\n';

  return 0;
}