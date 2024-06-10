#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 9, inf = 1e9;
int n, m;
string s1, s2;
int dp[N][N];

int fun(int i, int j) {
  if (i == n) {
    if (j == m) return 0;
    return m - j;
  }
  if (j == m) return n - i;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = inf;
  if (s1[i] == s2[j]) {
    ans = min(ans, fun(i + 1, j + 1));
  }
  ans = min(ans, 1 + fun(i + 1, j + 1));
  ans = min(ans, 1 + fun(i + 1, j));
  ans = min(ans, 1 + fun(i, j + 1));
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> s1 >> s2;
  n = s1.size(), m = s2.size();

  cout << fun(0, 0) << '\n';

  return 0;
}