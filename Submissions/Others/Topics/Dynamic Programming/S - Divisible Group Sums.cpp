#include <bits/stdc++.h>
using namespace std;
const int N = 205, M = 15, D = 25;
using ll = long long;
int n, q, m, d, a[N];
ll dp[N][D][M];

ll fun(int i, int sum, int taken) {
  if (taken > m) return 0;
  if (i == n + 1) {
    if (sum == 0 and taken == m) return 1;
    return 0;
  }
  ll &ans = dp[i][sum][taken];
  if (ans != -1) return ans;
  ans = fun(i + 1, (sum + ((a[i] % d) + d) % d) % d, taken + 1);
  ans += fun(i + 1, sum, taken);
  return ans;
}

int cs = 0;
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    cin >> d >> m;
    memset(dp, -1, sizeof dp);
    cout << fun(1, 0, 0) << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}