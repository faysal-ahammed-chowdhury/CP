#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1], b;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> b;
  a[0] = -2e9;
  for (int i = 1; i <= n; i++) {
    int x = min(a[i], b - a[i]);
    int y = max(a[i], b - a[i]);
    if (x >= a[i - 1]) a[i] = x;
    else a[i] = y;
    // cout << a[i] << ' ';
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