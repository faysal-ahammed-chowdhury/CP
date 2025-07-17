#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5005;
int a[N], dp[2][N];
int n, k;

int cs;
void solve() {
  cout << "Case " << ++cs << ": ";
  cin >> n >> k;
  int mx = -1e9;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  if (k == 0 and mx <= 0) {
    cout << mx << '\n';
    return;
  }

  if (mx <= 0) {
    cout << 0 << '\n';
    return;
  }

  int val = 0;
  for (int i = 0; i <= n; i++) {
    for (int rem = 0; rem <= k; rem++) {
      if (i == 0) {
        dp[1][rem] = 0;
        continue;
      }
      int &ans = dp[1][rem];
      ans = 0;
      ans = max(ans, a[i] + dp[0][rem]);
      if (rem > 0) ans = max(ans, dp[0][rem - 1]);
      val = max(val, ans);
    }
    for (int rem = 0; rem <= k; rem++) {
      dp[0][rem] = dp[1][rem];
    }
  }

  cout << val << '\n';
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