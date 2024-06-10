#include <bits/stdc++.h>
using namespace std;

string s;
int n, dp[202][202];

int fun(int i, int j) {
  if (i >= j) {
    return 0;
  }

  int &ans = dp[i][j];
  if (ans != -1) return ans;

  if (s[i] == s[j]) {
    ans = fun(i + 1, j - 1);
  }
  else {
    ans = 1 + fun(i + 1, j);
    ans = min(ans, 1 + fun(i, j - 1));
  }
  return ans;
}

int cs = 0;
void solve() {
  cin >> s;
  n = s.size();
  s = '.' + s;

  memset(dp, -1, sizeof dp);
  cout << "Case " << ++cs << ": ";
  cout << fun(1, n) << '\n';
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