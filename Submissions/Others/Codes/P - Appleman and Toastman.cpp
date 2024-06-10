#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1ll * (i + 1) * a[i];
  }
  ans -= a[n];

  cout << ans << '\n';

  return 0;
}