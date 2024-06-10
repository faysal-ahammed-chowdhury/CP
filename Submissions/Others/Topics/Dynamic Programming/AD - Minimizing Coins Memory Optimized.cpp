#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_VAL = 1e6 + 9, inf = 1e9;
int n, x, a[N], dp[2][MAX_VAL];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int amount = 0; amount <= x; amount++) {
      if (i == n + 1) {
        if (amount == 0) dp[0][amount] = 0;
        else dp[0][amount] = inf;
      }
      else {
        int &ans = dp[0][amount];
        ans = dp[1][amount];
        if (amount >= a[i]) ans = min(ans, 1 + dp[0][amount - a[i]]);
      }
    }
    for (int amount = 0; amount <= x; amount++) {
      dp[1][amount] = dp[0][amount];
    }
  }

  int ans = dp[0][x];
  cout << (ans >= inf ? -1 : ans) << '\n';

  return 0;
}