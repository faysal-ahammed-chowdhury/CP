#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 3005;
int n, a[N];
ll dp[2][N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      for (int last = 0; last < 2; last++) {
        if (i > j) {
          dp[last][i][j] = 0;
        }
        else {
          ll &ans = dp[last][i][j];
          ans = 0;
          if (last == 0) {
            ll ans1 = a[i] + dp[!last][i + 1][j];
            ll ans2 = a[j] + dp[!last][i][j - 1];
            ans = max(ans1, ans2);
          }
          else {
            ll ans1 = -a[i] + dp[!last][i + 1][j];
            ll ans2 = -a[j] + dp[!last][i][j - 1];
            ans = min(ans1, ans2);
          }
        }
      }
    }
  }

  cout << dp[0][1][n] << '\n';

  return 0;
}