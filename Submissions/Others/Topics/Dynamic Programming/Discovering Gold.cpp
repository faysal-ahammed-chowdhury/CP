#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N];
double dp[N];
bool vis[N];

double fun(int i) {
  if (i == n) {
    return a[n];
  }
  if (vis[i]) return dp[i];
  vis[i] = true;
  double ans = a[i];
  for (int k = 1; k <= 6; k++) {
    if (i + k <= n) {
      int div = min(6, n - i);
      ans += (1.0 / div) * fun(i + k);
    }
  }
  return dp[i] = ans;
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(vis, 0, sizeof vis);
  cout << "Case " << ++cs << ": ";
  cout << fixed << setprecision(10) << fun(1) << '\n';
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