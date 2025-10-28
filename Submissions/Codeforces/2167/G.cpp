#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 8005, inf = 1e18;
int a[N], c[N];
int n;
int dp[2][N];

// int f(int i, int last) {
//   if (i > n) return 0;
//   int ans = inf;
//   if (a[i] >= a[last]) {
//     ans = min(ans, f(i + 1, i));
//   }
//   ans = min(ans, c[i] + f(i + 1, last));
//   return ans;
// }

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  // cout << f(1, 0) << '\n';
  for (int i = 0; i <= 1; i++) {
    for (int last = 0; last <= n; last++) {
      dp[i][last] = inf;
    }
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int last = 0; last <= n; last++) {
      if (i > n) {
        dp[0][last] = 0;
        continue;
      }
      int &ans = dp[0][last];
      ans = inf;
      if (a[i] >= a[last]) {
        ans = min(ans, dp[1][i]);
      }
      ans = min(ans, c[i] + dp[1][last]);
    }
    for (int last = 0; last <= n; last++) {
      dp[1][last] = dp[0][last];
    }
  }

  cout << dp[0][0] << '\n';
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