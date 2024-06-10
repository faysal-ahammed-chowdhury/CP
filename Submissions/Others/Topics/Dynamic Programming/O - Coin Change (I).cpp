#include <bits/stdc++.h>
using namespace std;

const int N = 55, K = 1005, mod = 100000007;
int n, k, a[N], c[N], dp[N][K];

int fun(int i, int current_value) {
  if (i == n + 1) {
    if (current_value == k) return 1;
    return 0;
  }
  int &ans = dp[i][current_value];
  if (ans != -1) return ans;
  ans = fun(i + 1, current_value);
  for (int j = 1; j <= c[i]; j++) {
    int x = a[i] * j;
    if (current_value + x <= k) {
      ans = (ans + fun(i + 1, current_value + x)) % mod;
    }
  }
  return ans;
}

int cs = 0;
void solve() {
  memset(dp, -1, sizeof dp);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int x; cin >> c[i];
  }

  cout << "Case " << ++cs << ": ";
  cout << fun(1, 0) << '\n';
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