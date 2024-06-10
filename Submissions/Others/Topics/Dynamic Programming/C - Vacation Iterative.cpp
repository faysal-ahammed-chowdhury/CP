#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n, a[N], b[N], c[N], dp[N][5];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  for(int i = 1; i <= n; i++) {
    for(int last = 0; last <= 2; last++) {
      if(last == 0) {
        dp[i][last] = max(dp[i][last], b[i] + dp[i - 1][1]);
        dp[i][last] = max(dp[i][last], c[i] + dp[i - 1][2]);
      }
      else if(last == 1) {
        dp[i][last] = max(dp[i][last], a[i] + dp[i - 1][0]);
        dp[i][last] = max(dp[i][last], c[i] + dp[i - 1][2]);
      }
      else {
        dp[i][last] = max(dp[i][last], a[i] + dp[i - 1][0]);
        dp[i][last] = max(dp[i][last], b[i] + dp[i - 1][1]);
      }
    }
  }

  cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << '\n';

  return 0;
}