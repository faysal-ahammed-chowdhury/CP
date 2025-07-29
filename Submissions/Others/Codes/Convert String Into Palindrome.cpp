#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
int n, dp[N][N];
string s;

int cs;
void solve() {
  cin >> s;
  n = s.size();
  s = '.' + s;
  dp[n + 1][0] = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      if (i > j) dp[i][j] = 0;
      else {
        int &ans = dp[i][j];
        if (s[i] == s[j]) ans = dp[i + 1][j - 1];
        else ans = 1 + min(dp[i + 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << "Case " << ++cs << ": " << dp[1][n] << '\n';
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