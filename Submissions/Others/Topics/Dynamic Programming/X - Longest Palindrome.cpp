#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, dp[N][N];
string s;

int fun(int i, int j) {
  if (i > j) return 0;
  if (i == j) return 1;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = 0;
  if (s[i] == s[j]) {
    ans = max(ans, 2 + fun(i + 1, j - 1));
  }
  else {
    ans = max(ans, fun(i + 1, j));
    ans = max(ans, fun(i, j - 1));
  }
  return ans;
}

void solve() {
  getline(cin, s);
  n = s.size();
  memset(dp, -1, sizeof dp);
  cout << fun(0, n - 1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  cin.ignore();
  while(t--) {
    solve();
  }

  return 0;
}