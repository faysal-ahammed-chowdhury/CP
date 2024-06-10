#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 105;
int n, w, k, a[N], dp[N][K];

int cs;
void solve() {
  cin >> n >> w >> k;
  for (int i = 1; i <= n; i++) {
    int tmp; cin >> tmp >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = n + 1; i >= 1; i--) {
    for (int rem = 0; rem <= k; rem++) {
      if (i == n + 1 or rem  == 0) {
        dp[i][rem] = 0;
      }
      else {
        int now = a[i];
        int mx = now + w;
        auto it = upper_bound(a + 1, a + n + 1, mx);
        int go = it - &(a[1]) + 1;
        int paisi = it - &(a[i]);
        int &ans = dp[i][rem];
        ans = max(paisi + dp[go][rem - 1], dp[i + 1][rem]);
      }
    }
  }
  cout << "Case " << ++cs << ": ";
  cout << dp[1][k] << '\n';
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