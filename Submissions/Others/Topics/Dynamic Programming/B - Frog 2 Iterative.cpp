#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, inf = 2e9;
int n, k, height[N], dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> height[i];
  }

  dp[n] = 0;
  for(int i = n - 1; i >= 1; i--) {
    dp[i] = inf;
    for(int j = 1; j <= k; j++) {
      if(i + j <= n) {
        dp[i] = min(dp[i], abs(height[i] - height[i + j]) + dp[i + j]);
      }
    }
  }

  cout << dp[1] << '\n';

  return 0;
}