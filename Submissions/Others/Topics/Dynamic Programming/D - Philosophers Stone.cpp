#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int h, w, a[N][N], dp[2][N];

void solve() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = h + 1; i >= 0; i--) {
    for (int j = 1; j <= w; j++) {
      if (i == h + 1) {
        dp[0][j] = 0;
      }
      else {
        int &ans = dp[0][j];
        ans = a[i][j] + dp[1][j];
        if (j - 1 > 0) {
          ans = max(ans, a[i][j] + dp[1][j - 1]);
        }
        if (j + 1 <= w) {
          ans = max(ans, a[i][j] + dp[1][j + 1]);
        }
      }
    }
    for (int j = 1; j <= w; j++) {
      dp[1][j] = dp[0][j];
    }
  }

  int ans = 0;
  for (int x = 1; x <= w; x++) {
    ans = max(ans, dp[0][x]);
  }
  cout << ans << '\n';
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