#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_W = 1e5 + 9;
int n, w, weight[N], value[N];
long long dp[N][MAX_W];

long long fun(int i, int current_weight) {
  if(i > n) {
    return 0;
  }

  if(dp[i][current_weight] != -1) return dp[i][current_weight];

  long long ans = fun(i + 1, current_weight);
  if(current_weight + weight[i] <= w) {
    ans = max(ans, fun(i + 1, current_weight + weight[i]) + value[i]);
  }
  return dp[i][current_weight] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> n >> w;
  for(int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
  }

  cout << fun(1, 0) << '\n';

  return 0;
}