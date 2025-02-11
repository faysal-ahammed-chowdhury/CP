#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int j = 1; j <= m; j++) cin >> b[j];
  sort(b + 1, b + m + 1);
  for (int j = 1; j <= m; j++) {
    a[1] = min(a[1], b[j] - a[1]);
  }
  for (int i = 2; i <= n; i++) {
    int val = a[i - 1] + a[i];
    auto it = lower_bound(b + 1, b + m + 1, val);
    if (it != (b + m + 1)) {
      int x = min(a[i], *it - a[i]);
      int y = max(a[i], *it - a[i]);
      if (x >= a[i - 1]) a[i] = x;
      else a[i] = y;
    }
  }

  if (is_sorted(a + 1, a + n + 1)) cout << "YES\n";
  else cout << "NO\n";
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