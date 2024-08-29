#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_VAL = 1e5 + 9;
int a[N], c[N], n, m;
bitset<MAX_VAL> dp[N];

int cs;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  memset(dp, 0, sizeof dp);
  dp[n + 1][0] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= min(m, a[i] * c[i]); j += a[i]) {
      dp[i] |= dp[i + 1] << j;
    }
  }

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (dp[1][i]) ans++;
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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