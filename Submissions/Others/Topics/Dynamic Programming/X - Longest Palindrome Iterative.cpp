#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];

void solve() {
  string s; getline(cin, s);
  int n = s.size();
  memset(dp, 0, sizeof dp);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      if (i > j) dp[i][j] = 0;
      else if (i == j) dp[i][j] =  1;
      else {
        int &ans = dp[i][j];
        ans = 0;
        if (s[i] == s[j]) {
          ans = max(ans, 2 + dp[i + 1][j - 1]);
        }
        else {
          ans = max(ans, dp[i + 1][j]);
          ans = max(ans, dp[i][j - 1]);
        }
      }
    }
  }
  cout << dp[0][n - 1] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  cin.ignore();
  while (t--) {
    solve();
  }

  return 0;
}