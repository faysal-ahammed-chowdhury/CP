#include <bits/stdc++.h>
using namespace std;

const int N = 2005, W = 2005;
int n, w, value[N], weight[N], dp[2][W];

void solve() {
  cin >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int weight_capacity = 0; weight_capacity <= w; weight_capacity++) {
      if (i == 0) {
        dp[1][weight_capacity] = 0;
      }
      else {
        int &ans = dp[1][weight_capacity];
        if (weight_capacity >= weight[i]) {
          ans = value[i] + dp[0][weight_capacity - weight[i]];
        }
        ans = max(ans, dp[0][weight_capacity]);
      }
    }
    for (int weight_capacity = 0; weight_capacity <= w; weight_capacity++) {
      dp[0][weight_capacity] = dp[1][weight_capacity];
    }
  }
  cout << dp[1][w] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}