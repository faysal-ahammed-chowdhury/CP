#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n, height[N], dp[N];

int fun(int i) {
  if(i == n) return 0;
  if(dp[i] != -1) return dp[i];
  int ans = fun(i + 1) + abs(height[i + 1] - height[i]);
  if(i + 2 <= n) {
    ans = min(ans, fun(i + 2) + abs(height[i + 2] - height[i]));
  }
  return dp[i] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> height[i];
  }

  cout << fun(1) << '\n';

  return 0;
}