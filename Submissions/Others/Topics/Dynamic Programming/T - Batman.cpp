#include <bits/stdc++.h>
using namespace std;

#define len(x) (int)x.size()
const int N = 52;
int n, m, p;
string s1, s2, s3;
int dp[N][N][N];

int fun(int i, int j, int k) {
  if (i == n or j == m or k == p) return 0;
  int &ans = dp[i][j][k];
  if (ans != -1) return ans;
  if (s1[i] == s2[j] and s2[j] == s3[k]) {
    ans = max(ans, 1 + fun(i + 1, j + 1, k + 1));
  }
  ans = max(ans, fun(i + 1, j, k));
  ans = max(ans, fun(i, j + 1, k));
  ans = max(ans, fun(i, j, k + 1));
  return ans;
}

int cs = 0;
void solve() {
  cin >> s1 >> s2 >> s3;
  n = len(s1); m = len(s2); p = len(s3);
  memset(dp, -1, sizeof(dp));
  cout << "Case " << ++cs << ": " << fun(0, 0, 0) << '\n';
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