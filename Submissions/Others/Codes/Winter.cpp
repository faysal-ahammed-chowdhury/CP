#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, K = 1e6 + 9, inf = 1e9;
int n, k, a[N], dp[N];

int f(int i) {
  if (i > n) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  int mx = a[i] + (2 * k);
  auto idx = upper_bound(a + 1, a + n + 1, mx) - &a[1];
  ans = inf;
  for (int j = idx - 2; j <= idx; j++) {
    int diff = j - i + 1;
    if (diff >= 3) ans = min(ans, 1 + f(j + 1));
  }
  return ans;
}

int cs;
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  memset(dp, -1, sizeof dp);
  int ans = f(1);
  cout << "Case " << ++cs << ": " << (ans >= inf ? -1 : ans) << '\n';
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