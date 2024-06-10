#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, inf = 2e9;
int n, k, height[N], dp[N];

int fun(int i) {
  if(i == n) return 0;
  if(dp[i] != -1) return dp[i];
  int ans = inf;
  for(int j = 1; j <= k; j++) {
    if(i + j <= n) {
      ans = min(ans, abs(height[i] - height[i + j]) + fun(i + j));
    }
  }
  return dp[i] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> height[i];
  }

  cout << fun(1) << '\n';

  return 0;
}