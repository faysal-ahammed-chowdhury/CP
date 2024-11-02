#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1005, K = 105, inf = 1e18;
int n, a[N], b[N], dp[N][K];

int f(int i, int k) {
  if (i == n + 1) return k <= 0 ? 0 : inf;
  int &ans = dp[i][k];
  if (ans != -1) {
    return ans;
  }
  ans = f(i + 1, k);
  int cost = 0, len = a[i] + b[i] - 1;
  int x = a[i], y = b[i];
  for (int j = 1; j <= min(k, len); j++, y--) {
    if (x > y) swap(x, y);
    cost += x;
    if (x == 1 and y == 1) ans = min(ans, cost + f(i + 1, k - j - 1));
    else ans = min(ans, (cost) + f(i + 1, k - j));
  }
  return ans;
}

void solve() {
  int k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  // memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = -1;
    }
  }
  int ans = f(1, k);
  cout << (ans == inf ? -1 : ans) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}