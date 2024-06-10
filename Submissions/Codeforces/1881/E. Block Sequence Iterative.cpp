#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9;
int a[N], dp[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n + 1; i >= 1; i--) {
    if (i == n + 1) dp[i] = 0;
    else {
      int &ans = dp[i];
      ans = inf;
      if (i + a[i] <= n) {
        ans = dp[i + 1 + a[i]];
      }
      ans = min(ans, 1 + dp[i + 1]);
    }
  }

  cout << dp[1] << '\n';
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