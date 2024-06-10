#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int n, a[N];
long long dp[3];

int cnt = 0;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      dp[2] = dp[1] = dp[0] = 0;
    }
    else {
      long long &ans = dp[2];
      ans = max(ans, a[i] + dp[0]);
      ans = max(ans, dp[1]);
    }
    dp[0] = dp[1];
    dp[1] = dp[2];
  }
  cout << "Case " << ++cnt << ": ";
  cout << dp[2] << '\n';
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