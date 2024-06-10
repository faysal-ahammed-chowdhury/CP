#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    a[i] ^= a[i - 1];
  }
  long long ans = 0;
  for (int k = 0; k < 30; k++) {
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i <= n; i++) {
      if (a[i] & (1 << k)) {
        cnt1++;
      }
      else {
        cnt0++;
      }
    }
    ans += 1ll * cnt1 * cnt0 * (1 << k);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}