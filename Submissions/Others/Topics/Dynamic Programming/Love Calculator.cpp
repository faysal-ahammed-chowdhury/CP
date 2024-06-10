#include <bits/stdc++.h>
using namespace std;

const int N = 32, inf = 1e9;
string s1, s2;
int n, m, dp[N][N];
long long dp2[N][N];

int fun(int i, int j) {
  if (i == n + 1) {
    return m - j + 1;
  }
  if (j == m + 1) {
    return n - i + 1;
  }
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = inf;
  if (s1[i] == s2[j]) {
    ans = min(ans, 1 + fun(i + 1, j + 1));
  }
  else {
    ans = min(ans, 1 + fun(i + 1, j));
    ans = min(ans, 1 + fun(i, j + 1));
  }
  return ans;
}

long long fun2(int i, int j) {
  if (i == n + 1) {
    return 1;
  }
  if (j == m + 1) {
    return 1;
  }
  if (dp2[i][j] != -1) return dp2[i][j];
  int ans = fun(i, j);
  if (s1[i] == s2[j]) {
    return dp2[i][j] = fun2(i + 1, j + 1);
  }
  else {
    long long cnt = 0;
    if (1 + fun(i + 1, j) == ans) {
      cnt += fun2(i + 1, j);
    }
    if (1 + fun(i, j + 1) == ans) {
      cnt += fun2(i, j + 1);
    }
    return dp2[i][j] = cnt;
  }
  return -inf;
} 

int cs;
void solve() {
  cin >> s1 >> s2;
  n = s1.size(), m = s2.size();
  s1 = '.' + s1, s2 = '.' + s2;
  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));
  cout << "Case " << ++cs << ": ";
  cout << fun(1, 1) << ' ' << fun2(1, 1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}