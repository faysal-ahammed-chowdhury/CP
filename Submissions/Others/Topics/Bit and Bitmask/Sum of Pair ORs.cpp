#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     ans += a[i] | a[j];
  //   }
  // }
  // cout << ans << '\n';

  for (int k = 0; k < 30; k++) {
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] & (1 << k)) {
        cnt1++;
      }
      else {
        cnt0++;
      }
    }
    ans += 1ll * cnt1 * n * (1 << k);
    ans += 1ll * cnt0 * cnt1 * (1 << k);
  }
  cout << ans << '\n';

  return 0;
}