#include <bits/stdc++.h>
using namespace std;
#define len(x) (int)x.size();
const int N = 3005;
string s1, s2;
int n, m, dp[N][N];

void path(int i, int j) {
  if (i >= n or j >= m) return;
  if (s1[i] == s2[j]) {
    cout << s1[i];
    path(i + 1, j + 1);
    return;
  }
  int ans1 = dp[i + 1][j];
  int ans2 = dp[i][j + 1];
  if (ans1 > ans2) {
    path(i + 1, j);
  }
  else {
    path(i, j + 1);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> s1 >> s2;
  n = len(s1); m = len(s2);

  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      if (i == n or j == m) dp[i][j] = 0;
      else {
        int &ans = dp[i][j];
        if (s1[i] == s2[j]) {
          ans = 1 + dp[i + 1][j + 1];
        }
        ans = max(ans, dp[i + 1][j]);
        ans = max(ans, dp[i][j + 1]);
      }
    }
  }

  path(0, 0);

  return 0;
}