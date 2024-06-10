#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 62;
string s;
int n;
ll dp[N][N];

ll fun(int i, int j) {
  if (i > j) return 0;
  ll &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = fun(i + 1, j) + fun(i, j - 1) - fun(i + 1, j - 1);
  if (s[i] == s[j]) {
    ans += 1 + fun(i + 1, j - 1);
  }
  return ans;
}

int cs;
void solve() {
  cin >> s;
  n = s.size();
  s = '.' + s;
  memset(dp, -1, sizeof(dp));
  cout << "Case " << ++cs << ": ";
  cout << fun(1, n) << '\n';
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