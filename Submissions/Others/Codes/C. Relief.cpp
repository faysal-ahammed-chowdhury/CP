#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int a[N], b[N], n, m, l, r;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> l >> r;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int low = l - a[i], high = r - a[i];
    ans += upper_bound(b + 1, b + m + 1, high) - lower_bound(b + 1, b + m + 1, low);
  }
  cout << ans << '\n';

  return 0;
}