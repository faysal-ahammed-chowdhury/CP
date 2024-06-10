#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 105, MAX_VAL = 1e3 + 9;
const ll inf = 1e11 + 9;
int n, w, weight[N], value[N];
ll dp[N][MAX_VAL * N];

ll fun(int i, int current_value) {
  if (i == n + 1) {
    if (current_value == 0) return 0;
    else return inf;
  }
  ll &ans = dp[i][current_value];
  if (ans != -1) return ans;
  ans = fun(i + 1, current_value);
  if (current_value - value[i] >= 0) {
    ans = min(ans, weight[i] + fun(i + 1, current_value - value[i]));
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
  }
  memset(dp, -1, sizeof(dp));
  int ans = 0;
  for (int total_value = 1; total_value <= n * 1000; total_value++) {
    if (fun(1, total_value) <= w) {
      ans = max(ans, total_value);
    }
  }
  cout << ans << '\n';
  return 0;
}