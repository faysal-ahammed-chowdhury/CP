#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, inf = 1e9;
int n, dp[N][30][2];
string s;

int get(char c) {
  if (c == '?') return 26;
  return c - 'a';
}

int f(int i, char last, bool taken) {
  if (i >= n) return ((taken and last == '?') ? 0 : inf);
  int &ans = dp[i][get(last)][taken];
  if (ans != -1) return ans;
  ans = inf;
  if (last == '?') ans = min(ans, f(i + 1, s[i], taken));
  else if (s[i] != last) ans = min(ans, 1 + f(i + 1, '?', true));
  if (last != '?') ans = min(ans, f(i + 1, last, taken));
  // cout << i << ' ' << last << ' ' << taken << ' ' << ans << '\n';
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  memset(dp, -1, sizeof dp);
  int ans = f(0, '?', false);
  cout << (ans >= inf ? -1 : ans) << '\n';

  return 0;
} 