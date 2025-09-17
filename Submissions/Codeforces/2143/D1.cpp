#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 305, mod = 1e9 + 7;
int n, a[N], dp[N][N][N];

int f(int i, int mx, int mid_mx) {
  if (i > n) return 1;
  int &ans = dp[i][mx][mid_mx];
  if (ans != -1) return ans;
  ans = f(i + 1, mx, mid_mx);
  int new_mid_mx = (a[i] < mx ? max(mid_mx, a[i]) : mid_mx);
  if (a[i] >= mid_mx) {
    ans += f(i + 1, max(mx, a[i]), new_mid_mx);
    ans %= mod;
  }
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cout << f(1, 0, 0) << '\n';
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