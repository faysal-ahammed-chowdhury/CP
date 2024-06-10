#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, s, m, l; cin >> n >> s >> m >> l;
  int ans = 1e9;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int k = n - i - j;
      int need1 = ((i + 5) / 6);
      int need2 = ((j + 7) / 8);
      int need3 = ((k + 11) / 12);
      ans = min(ans, (need1 * s) + (need2 * m) + (need3 * l));
    }
  }
  cout << ans << '\n';

  return 0;
}