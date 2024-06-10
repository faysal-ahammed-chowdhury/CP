#include <bits/stdc++.h>
using namespace std;

const int N = 52;
int dp[N][N][N];

int cs = 0;
void solve() {
  string s1, s2, s3; cin >> s1 >> s2 >> s3;
  int n = s1.size(), m = s2.size(), p = s3.size();
  memset(dp, 0, sizeof(dp));
  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      for (int k = p; k >= 0; k--) {
        if (i == n or j == m or k == p) {
          dp[i][j][k] = 0;
        }
        else {
          int &ans = dp[i][j][k];
          if (s1[i] == s2[j] and s2[j] == s3[k]) {
            ans = max(ans, 1 + dp[i + 1][j + 1][k + 1]);
          }
          else {
            ans = max(ans, dp[i + 1][j][k]);
            ans = max(ans, dp[i][j +1][k]);
            ans = max(ans, dp[i][j][k + 1]);
          }
        }
      }
    }
  }
  cout << "Case " << ++cs << ": " << dp[0][0][0] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}