#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
string s, t;
int n;
int dp[N][5];

int fun(int i, int idx) {
  if (idx == 4) {
    return i;
  }
  if (i == n) {
    return 0;
  }
  int &ans = dp[i][idx];
  if (ans != -1) {
    return ans;
  }
  if (s[i] == t[idx]) {
    ans = fun(i + 1, idx + 1);
  }
  else {
    ans = fun(i + 1, idx);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  t = "sysu";
  n = s.size();

  memset(dp, -1, sizeof(dp));

  long long ans = 0;
  int last = -1;
  for (int i = 1; i <= n; i++) {
    int x = fun(i - 1, 0);
    if (x > i) {
      int y;
      if (last == -1) {
        y = i;
      }
      else {
        y = i - last;
      }
      ans += 1ll * y * (n - x + 1);
      last = i;
    }
  }
  cout << ans << '\n';

  return 0;
}