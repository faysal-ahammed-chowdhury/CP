#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9;
int n, m, a[N], b[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  int l, r; cin >> l >> r;

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int mn = l - a[i], mx = r - a[i];
    // cout << mn << ' ' << mx << ' ' << upper_bound(b + 1, b + m + 1, mx) - upper_bound(b + 1, b + m + 1, mn) << '\n';
    ans += upper_bound(b + 1, b + m + 1, mx) - lower_bound(b + 1, b + m + 1, mn);
  }

  cout << ans << '\n';

  return 0;
}