#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 55, MAXH = 1e3 * N;
const ll inf = 5e9 + 9;
int n, x;
int cost[N], happiness[N];
ll dp[N][MAXH];

void solve() {
  cin >> n >> x;
  int tot_happiness = 0;
  for (int i = 1; i <= n; i++) {
    cin >> cost[i] >> happiness[i];
    tot_happiness += happiness[i];
  }
  
  for (int i = 0; i <= n; i++) {
    for (int h = 0; h <= tot_happiness; h++) {
      if (i == 0) {
        dp[i][h] = h == 0 ? 0 : inf;
      }
      else {
        ll &ans = dp[i][h];
        ans = dp[i - 1][h];
        if (h - happiness[i] >= 0) {
          ll need = dp[i - 1][h - happiness[i]] + cost[i];
          if (need <= (1ll * (i - 1) * x)) {
            ans = min(ans, need);
          }
        }
      }
    }
  }

  for (int i = tot_happiness; i >= 0; i--) {
    if (dp[n][i] < inf) {
      cout << i << '\n';
      return;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}