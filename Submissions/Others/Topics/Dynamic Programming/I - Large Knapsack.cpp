#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

const int N = 505, W = 2e6 + 9;
int n, w, value[N], weight[N];
// int dp[2][W];
gp_hash_table<int, int> dp[N];

int fun(int i, int weight_capacity) {
  if (i == 0) {
    return 0;
  }
  if (dp[i].find(weight_capacity) != dp[i].end()) {
    return dp[i][weight_capacity];
  }
  int &ans = dp[i][weight_capacity];
  ans = fun(i - 1, weight_capacity);
  if (weight_capacity >= weight[i]) {
    ans = max(ans, value[i] + fun(i - 1, weight_capacity - weight[i]));
  }
  return ans;
}

void solve() {
  cin >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> value[i] >> weight[i];
  }
  // for (int i = 0; i <= n; i++) {
  //   for (int weight_capacity = 0; weight_capacity <= w; weight_capacity++) {
  //     if (i == 0) {
  //       dp[i][weight_capacity] = 0;
  //     }
  //     else {
  //       int &ans = dp[1][weight_capacity];
  //       if (weight_capacity >= weight[i]) {
  //         ans = value[i] + dp[0][weight_capacity - weight[i]];
  //       }
  //       ans = max(ans, dp[0][weight_capacity]);
  //     }
  //   }
  //   for (int weight_capacity = 0; weight_capacity <= w; weight_capacity++) {
  //     dp[0][weight_capacity] = dp[1][weight_capacity];
  //   }
  // }
  // cout << dp[1][w] << '\n';
  cout << fun(n, w) << '\n';
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