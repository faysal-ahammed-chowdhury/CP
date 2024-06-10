#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 105, MAX_W = 1e5 + 9;
int n, w, weight[N], value[N];
long long dp[N][MAX_W];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> w;
  for(int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
  }

  for(int i = n; i >= 1; i--) {
    for(int current_weight = 0; current_weight <= w; current_weight++) {
      ll &ans = dp[i][current_weight];
      ans = dp[i + 1][current_weight];
      if(current_weight >= weight[i]) {
        ans = max(ans, value[i] + dp[i + 1][current_weight - weight[i]]);
      }
    }
  }

  cout << dp[1][w] << '\n';

  return 0;
}