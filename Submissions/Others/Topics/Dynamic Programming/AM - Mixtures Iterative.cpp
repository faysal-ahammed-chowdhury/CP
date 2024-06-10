#include <bits/stdc++.h>
using namespace std;

const int N = 105, mod = 100, inf = 2e9;
int n, a[N];
int dp[N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      dp[i][i] = 0;
    }
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        int &ans = dp[i][j];
        int total = 0;
        for (int k = i; k <= j; k++) {
          total += a[k];
        }
        int sum = 0; ans = inf;
        for (int k = i; k < j; k++) {
          sum += a[k];
          int another = total - sum;
          int x = (sum % mod) * (another % mod) + (dp[i][k] + dp[k + 1][j]);
          ans = min(ans, x);
        }
      }
    }
    cout << dp[1][n] << '\n';
  }

  return 0;
}