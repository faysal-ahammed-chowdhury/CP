#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 105, MAX_VAL = 1e3 + 9;
const ll inf = 1e11 + 9;
int n, w, weight[N], value[N];
ll dp[N][MAX_VAL * N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
  }

  int max_val = 0;
  for (int i = n + 1; i >= 1; i--) {
    for (int current_value = 0; current_value <= n * 1000; current_value++) {
      if (i == n + 1) {
        if (current_value == 0) dp[i][current_value] = 0;
        else dp[i][current_value] = inf;
      }
      else {
        ll &ans = dp[i][current_value];
        ans = dp[i + 1][current_value];
        if (current_value - value[i] >= 0) {
          ans = min(ans, weight[i] + dp[i + 1][current_value - value[i]]);
        }
        if (ans <= w) {
          max_val = max(max_val, current_value);
        }
      }
    }
  }
  cout << max_val << '\n';
  return 0;
}