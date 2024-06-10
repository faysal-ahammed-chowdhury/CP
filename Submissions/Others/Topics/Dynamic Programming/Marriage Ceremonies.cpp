#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int n, a[N][N], dp[N][(1 << N) + 2];

int fun(int i, int mask) {
  if (i == n + 1) {
    return 0;
  }
  int &ans = dp[i][mask];
  if (ans != -1) return ans;

  ans = 0;
  for (int j = 1; j <= n; j++) {
    if (!(mask & (1 << j))) {
      ans = max(ans, a[i][j] + fun(i + 1, mask | (1 << j)));
    }
  }
  return ans;
}

int cs = 0;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  memset(dp, -1, sizeof dp);
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