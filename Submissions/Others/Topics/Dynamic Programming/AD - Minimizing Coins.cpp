#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_VAL = 1e6 + 9, inf = 1e9;
int n, x, a[N], dp[N][MAX_VAL];

// int fun(int i, int amount) {
//   if (i == n + 1) {
//     if (amount == 0) return 0;
//     return inf;
//   }
//   int &ans = dp[i][amount];
//   if (ans != -1) return ans;
//   ans = fun(i + 1, amount);
//   if (amount >= a[i]) ans = min(ans, 1 + fun(i, amount - a[i]));
//   return ans;
// }

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
        if (amount == 0) dp[i][amount] = 0;
        else dp[i][amount] = inf;
      }
      else {
        int &ans = dp[i][amount];
        ans = dp[i + 1][amount];
        if (amount >= a[i]) ans = min(ans, 1 + dp[i][amount - a[i]]);
      }
    }
  }

  int ans = dp[1][x];
  cout << (ans >= inf ? -1 : ans) << '\n';

  return 0;
}