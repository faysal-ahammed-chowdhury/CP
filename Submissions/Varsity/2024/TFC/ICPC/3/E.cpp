#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  bool all_zero = true;
  int cnt[70];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_zero &= a[i] == 0;
    if (a[i] == 0) continue;
    int msb = 63 - __builtin_clzll(a[i]);
    cnt[msb]++;
  }

  if (all_zero) {
    cout << 1 << '\n';
    return;
  }

  int ans = 0;
  for (int k = 0; k <= 65; k++) {
    ans = max(ans, cnt[k]);
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