#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_VAL = 1e6 + 9, mod = 1e9 + 7;
int n, x, a[N], dp[MAX_VAL];

int fun(int amount) {
  if (amount == 0) return 1;
  int &ans = dp[amount];
  if (ans != -1) return ans;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (amount >= a[i]) {
      ans += fun(amount - a[i]);
      if (ans >= mod) {
        ans -= mod;
      }
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof dp);

  cout << fun(x) << '\n';

  return 0;
}