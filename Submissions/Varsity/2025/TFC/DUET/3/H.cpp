#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3005, inf = 1e9;
int n, m, a[N];
int dp[N][N][2];

int f(int i, int need, bool last) {
  if (i > n) {
    return need == 0 ? (last ? 0 : 1) : inf;
  }

  int &ans = dp[i][need][last];
  if (ans != -1) return ans;

  ans = f(i + 1, need, false);
  if (need - a[i] >= 0) {
    if (last) ans = min(ans, f(i + 1, need - a[i], true));
    else ans = min(ans, 1 + f(i + 1, need - a[i], true));
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= m; i++) {
    int ans = f(1, i, true);
    cout << (ans >= inf ? -1 : ans) << '\n';
  }

  return 0;
}