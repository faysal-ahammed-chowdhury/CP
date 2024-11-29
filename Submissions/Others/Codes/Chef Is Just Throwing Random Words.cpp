#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> dp(60, 0);
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 30; k++) {
      if (CHECK(a[i], k)) dp[k]++;
    } 
  }


  for (int k = 1; k < 60; k++) {
    dp[k] += dp[k - 1] / 2;
  }

  long long ans = 0;
  for (int k = 0; k < 60; k++) {
    if (dp[k]) ans += (1ll << k);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}