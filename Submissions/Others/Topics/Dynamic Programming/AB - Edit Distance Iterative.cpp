#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 9, inf = 1e9;
int n, m;
string s1, s2;
int dp[N][N];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  cin >> s1 >> s2;
  n = s1.size(), m = s2.size();

  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      if (i == n) {
        if (j == m) dp[i][j] = 0;
        dp[i][j] = m - j;
      }
      else if (j == m) dp[i][j] = n  - i;
      else {
        int &ans = dp[i][j];
        ans = inf;
        if (s1[i] == s2[j]) {
          ans = min(ans, dp[i + 1][j + 1]);
        }
        ans = min(ans, 1 + dp[i + 1][j + 1]);
        ans = min(ans, 1 + dp[i + 1][j]);
        ans = min(ans, 1 + dp[i][j + 1]);
      }
    }
  }

  cout << dp[0][0] << '\n';

  return 0;
}