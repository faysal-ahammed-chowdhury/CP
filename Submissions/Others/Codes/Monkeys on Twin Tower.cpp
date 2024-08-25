#include <bits/stdc++.h>
using namespace std;

const int N = 1005, inf = 1e9;
int a[N], b[N], c[N], d[N];
int n, dp[N][2];

int f(int i, bool left) {
  if (i == n) {
    if (left) return a[n];
    return b[n];
  }
  int &ans = dp[i][left];
  if (ans != -1) return ans;
  ans = inf;
  if (left) {
    ans = min(ans, a[i] + f(i + 1, true));
    ans = min(ans, (a[i] + c[i]) + f(i + 1, false));
  }
  else {
    ans = min(ans, b[i] + f(i + 1, false));
    ans = min(ans, (b[i] + d[i]) + f(i + 1, true));
  }
  return ans;
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i < n; i++) cin >> c[i];
  for (int i = 1; i < n; i++) cin >> d[i];
  memset(dp, -1, sizeof dp);
  cout << "Case " << ++cs << ": ";
  cout << min(f(1, true), f(1, false)) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}