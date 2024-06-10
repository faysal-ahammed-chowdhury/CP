#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 105, MAX_W = 1e5 + 9;
int n, w, value[N], weight[N];
ll dp[N][MAX_W];

ll fun(int i, int current_weight) {
  if(i == 0) return 0;
  ll &ans = dp[i][current_weight];
  if(ans != -1) return ans;
  ans = fun(i - 1, current_weight);
  if(current_weight + weight[i] <= w) {
    ans = max(ans, value[i] + fun(i - 1, current_weight + weight[i]));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // memset(dp, -1, sizeof dp);

  cin >> n >> w;
  for(int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
  }

  // cout << fun(n, 0) << '\n';

  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int current_weight = 1; current_weight <= w; current_weight++) {
      dp[i][current_weight] = dp[i - 1][current_weight];
      if(current_weight >= weight[i]) {
        dp[i][current_weight] = max(
          dp[i][current_weight],
          dp[i - 1][current_weight - weight[i]] + value[i]
        );
      }
    }
  }

  cout << dp[n][w] << '\n';

  return 0;
}