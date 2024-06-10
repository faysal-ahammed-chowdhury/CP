#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_VAL = 1e6 + 9, mod = 1e9 + 7;
int n, x, a[N], dp[MAX_VAL];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int amount = 0; amount <= x; amount++) {
    if (amount == 0) {
      dp[amount] = 1;
    }
    else {
      int &ans = dp[amount];
      ans = 0;
      for (int i = 1; i <= n; i++) {
        if (amount >= a[i]) {
          ans += dp[amount - a[i]];
          if (ans >= mod) {
            ans -= mod;
          }
        }
      }
    }
  }

  cout << dp[x] << '\n';

  return 0;
}