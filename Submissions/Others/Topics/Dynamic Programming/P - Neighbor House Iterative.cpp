#include <bits/stdc++.h>
using namespace std;

const int N = 25, inf = 1e9;
int a[N][5], dp[N][5];

int cs = 0;
void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1] >> a[i][2] >> a[i][3];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int last = 3; last >= 0; last--) {
      if (i == n + 1) {
        dp[i][last] = 0;
      }
      else {
        int &ans = dp[i][last];
        ans = inf;
        for (int k = 1; k <= 3; k++) {
          if (last == k) continue;
          ans = min(ans, a[i][k] + dp[i + 1][k]);
        }
      }
    }
  }

  cout << "Case " << ++cs << ": ";
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