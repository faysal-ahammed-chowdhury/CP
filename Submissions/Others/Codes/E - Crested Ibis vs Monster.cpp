#include <bits/stdc++.h>
using namespace std;

const int N = 1005, H = 10005, inf = 1e9;
int n, h, a[N], b[N], dp[H];

int f(int cur_h) {
  if (cur_h <= 0) return 0;
  int &ans = dp[cur_h];
  if (ans != -1) return ans;
  ans = inf;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, b[i] + f(cur_h - a[i]));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> h >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  memset(dp, -1, sizeof dp);
  cout << f(h) << '\n';

  return 0;
}