#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, inf = 2e9;
int n, dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  dp[0] = 0;

  for(int i = 1; i <= n; i++) {
    dp[i] = inf;
    int x = i;
    while(x > 0) {
      int last = x % 10;
      x /= 10;
      if(last != 0) {
        dp[i] = min(dp[i], 1 + dp[i - last]);
      }
    }
  }

  cout << dp[n] << '\n';

  return 0;
}