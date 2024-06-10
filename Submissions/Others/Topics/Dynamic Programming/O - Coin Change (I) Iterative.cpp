#include <bits/stdc++.h>
using namespace std;

const int N = 55, K = 1005, mod = 100000007;
int n, k, a[N], c[N], dp[N][K];

int cs = 0;
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int x; cin >> c[i];
  }

  cout << "Case " << ++cs << ": ";

  for (int i = n + 1; i >= 1; i--) {
    for (int current_value = 0; current_value <= k; current_value++) {
      int &ans = dp[i][current_value];
      if (i == n + 1) {
        if (current_value == k) ans = 1;
        else ans = 0;
      }
      else {
        ans = dp[i + 1][current_value];
        for (int j = 1; j <= c[i]; j++) {
          int x = a[i] * j;
          if (current_value + x <= k) {
            ans = (ans + dp[i + 1][current_value + x]) % mod;
          }
        }
      }
    }
  }

  cout << dp[1][0] << '\n';
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