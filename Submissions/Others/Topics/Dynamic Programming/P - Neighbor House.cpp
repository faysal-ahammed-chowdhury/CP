#include <bits/stdc++.h>
using namespace std;

const int N = 25, inf = 1e9;
int n, a[N][5], dp[N][5];

int fun(int i, int last) {
  if (i == n + 1) return 0;
  int &ans = dp[i][last];
  if (ans != -1) return ans;
  ans = inf;
  for (int k = 1; k <= 3; k++) {
    if (last == k) continue;
    ans = min(ans, a[i][k] + fun(i + 1, k));
  }
  return ans;
}

int cs = 0;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1] >> a[i][2] >> a[i][3];
  }

  memset(dp, -1, sizeof(dp));

  cout << "Case " << ++cs << ": ";
  cout << fun(1, 0) << '\n';
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