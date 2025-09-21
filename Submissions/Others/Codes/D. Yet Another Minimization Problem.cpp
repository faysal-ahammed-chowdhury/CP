#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 105;
int n, a[N], b[N];
ll dp[N][N * N];

ll f(int i, int sum1, int sum2) {
  if (i > n) return 0;
  ll &ans = dp[i][sum1];
  if (ans != -1) return ans;
  ans = (2ll * a[i] * sum1) + (2ll * b[i] * sum2) + f(i + 1, sum1 + a[i], sum2 + b[i]);
  ans = min(ans, (2ll * b[i] * sum1) + (2ll * a[i] * sum2) + f(i + 1, sum1 + b[i], sum2 + a[i]));
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  memset(dp, -1, sizeof dp);
  ll ans = f(1, 0, 0);
  for (int i = 2; i <= n; i++) {
    ans += 1ll * (i - 1) * a[i] * a[i];
    ans += 1ll * (i - 1) * b[i] * b[i];
  }

  for (int i = 1; i <= n; i++) {
    ans += 1ll * (n - i) * a[i] * a[i];
    ans += 1ll * (n - i) * b[i] * b[i];
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}