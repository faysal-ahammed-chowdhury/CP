#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18;
const int N = 405;
int n, a[N];
long long dp[N][N];

ll fun(int i, int j) {
  if (i == j) return 0;
  ll &ans = dp[i][j];
  if (ans != -1) return ans;
  ll cur = 0;
  for (int x = i; x <= j; x++) {
    cur += a[x];
  }
  ans = inf;
  for (int x = i; x < j; x++) {
    ans = min(ans, cur + fun(i, x) + fun(x + 1, j));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof(dp));

  cout << fun(1, n) << '\n';

  return 0;
}